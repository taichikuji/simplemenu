#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <SDL/SDL_events.h>

FILE * fp;
int loggingEnabled;

void enableLogging() {
	loggingEnabled = 1;
}

void openLogFile() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char pathToLogFilePlusFileName[300];
	snprintf(pathToLogFilePlusFileName,sizeof(pathToLogFilePlusFileName),"%s/.simplemenu/%d-%02d-%02d.log",getenv("HOME"),tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	fp = fopen(pathToLogFilePlusFileName, "a");
}

void logMessage(const char* tag, const char* function, const char* message) {
	if (loggingEnabled) {
		time_t now;
		time(&now);
		char *time = ctime(&now);
		time[strlen(time)-1]='\0';
		if (fp==NULL) {
			openLogFile();
		}
		printf("%s | %-5s | %-40s | %s\n", time, tag, function, message);
		fprintf(fp,"%s | %-5s | %-40s | %s\n", time, tag, function, message);

	}
}

void closeLogFile() {
	if (fp!=NULL) {
		fclose(fp);
	}
}

int isLoggingEnabled() {
	return loggingEnabled;
}

void pushEvent() {
//    SDL_Event sdlevent;
//    sdlevent.type = SDL_MOUSEMOTION;
//    sdlevent.motion.x = 1;
//    SDL_PushEvent(&sdlevent);
}

/* Safe directory copy function to replace unsafe system() calls
 * Returns 0 on success, -1 on failure */
int safeCopyDirectory(const char* src, const char* dest) {
	struct stat st;
	struct dirent *entry;
	DIR *dir;
	char srcPath[1024];
	char destPath[1024];
	FILE *srcFile, *destFile;
	char buffer[8192];
	size_t bytes;
	
	/* Check if source exists */
	if (stat(src, &st) != 0) {
		return -1;
	}
	
	/* Create destination directory */
	if (mkdir(dest, 0700) != 0 && errno != EEXIST) {
		return -1;
	}
	
	/* If source is a file, just copy it */
	if (!S_ISDIR(st.st_mode)) {
		srcFile = fopen(src, "rb");
		if (srcFile == NULL) return -1;
		
		destFile = fopen(dest, "wb");
		if (destFile == NULL) {
			fclose(srcFile);
			return -1;
		}
		
		while ((bytes = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
			if (fwrite(buffer, 1, bytes, destFile) != bytes) {
				fclose(srcFile);
				fclose(destFile);
				return -1;
			}
		}
		
		fclose(srcFile);
		fclose(destFile);
		return 0;
	}
	
	/* Source is a directory - copy recursively */
	dir = opendir(src);
	if (dir == NULL) {
		return -1;
	}
	
	while ((entry = readdir(dir)) != NULL) {
		/* Skip . and .. */
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
			continue;
		}
		
		/* Build paths */
		snprintf(srcPath, sizeof(srcPath), "%s/%s", src, entry->d_name);
		snprintf(destPath, sizeof(destPath), "%s/%s", dest, entry->d_name);
		
		/* Recursively copy */
		if (stat(srcPath, &st) == 0) {
			if (S_ISDIR(st.st_mode)) {
				if (safeCopyDirectory(srcPath, destPath) != 0) {
					closedir(dir);
					return -1;
				}
			} else {
				srcFile = fopen(srcPath, "rb");
				if (srcFile == NULL) continue;
				
				destFile = fopen(destPath, "wb");
				if (destFile == NULL) {
					fclose(srcFile);
					continue;
				}
				
				while ((bytes = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
					fwrite(buffer, 1, bytes, destFile);
				}
				
				fclose(srcFile);
				fclose(destFile);
			}
		}
	}
	
	closedir(dir);
	return 0;
}
