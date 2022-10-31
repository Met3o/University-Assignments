#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fts.h>

int deletedirP(int argc, char* argv[]){
	char *name = argv[2];
	int ret = 0;
	FTS *ftsp = NULL;
	FTSENT *curr;

	char *files[] = { (char*) name, NULL};
	ftsp = fts_open(files, FTS_NOCHDIR | FTS_PHYSICAL | FTS_XDEV, NULL);
	if (!ftsp) {
		fprintf(stderr, "%s%s: fts_open failed: \n", name, strerror(errno));
		ret = -1;
		goto finish;
	}
	while ((curr = fts_read(ftsp))){
		switch (curr->fts_info){
		case FTS_NS:
		case FTS_DNR:
		case FTS_ERR:
			fprintf(stderr, "%s: fts_read error: %s\n",
				curr->fts_accpath, strerror(curr->fts_errno));
			break;
		case FTS_DC:
		case FTS_DOT:
		case FTS_NSOK:
			break;
		case FTS_D:
			break;
		case FTS_DP:
		case FTS_F:
		case FTS_SL:
		case FTS_SLNONE:
		case FTS_DEFAULT:
			if (remove(curr->fts_accpath) < 0){
				fprintf(stderr, "%s: Failed to remove: %s\n",
					curr->fts_path, strerror(curr->fts_errno));
				ret = -1;
			}
			break;
		}
	}
	finish:
		if (ftsp){
			fts_close(ftsp);
	}
	return ret;
}
