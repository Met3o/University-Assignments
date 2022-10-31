#ifdef _WIN32
const char SEP = '\\';
#else
const char SEP = '/';
#endif

bool rw_create_dir(const char *name)
{
    str_builder_t  *sb;
    char          **parts;
    size_t          num_parts;
    size_t          i;
    bool            ret = true;

    if (name == NULL || *name == '\0')
        return false;

    parts = str_split(name, strlen(name), SEP, &num_parts, 0);
    if (parts == NULL || num_parts == 0) {
        str_split_free(parts, num_parts);
        return false;
    }

    sb = str_builder_create();
    i  = 0;
#ifdef _WIN32
    /* If the first part has a ':' it's a drive. E.g 'C:'. We don't
     * want to try creating it because we can't. We'll add it to base
     * and move forward. The next part will be a directory we need
     * to try creating. */
    if (strchr(parts[0], ':')) {
        i++;
        str_builder_add_str(sb, parts[0], strlen(parts[0]));
        str_builder_add_char(sb, SEP);
    }
#else
    if (*name == '/') {
        str_builder_add_char(sb, SEP);
    }
#endif

    for ( ; i<num_parts; i++) {
        if (parts[i] == NULL || *(parts[i]) == '\0') {
            continue;
        }

        str_builder_add_str(sb, parts[i], strlen(parts[i]));
        str_builder_add_char(sb, SEP);

#ifdef _WIN32
        if (CreateDirectory(str_builder_peek(sb), NULL) == FALSE) {
            if (GetLastError() != ERROR_ALREADY_EXISTS) {
                ret = false;
                goto done;
            }
        }
#else
        if (mkdir(str_builder_peek(sb), 0774) != 0)
            if (errno != EEXIST) {
                ret = false;
                goto done;
            }
#endif
    }

done:
    str_split_free(parts, num_parts);
    str_builder_destroy(sb);
    return ret;
}
