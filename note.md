- It is fine that we just assign a bare inode to a regular file inside overlay. 
- Operate with a file (read, write, ..) within a directory, *ovl_dir_open* is called on that directory.
  ====> Wrong, because you hit tab. !!!!!!!

- Processes deal directly with files, not inodes, dentries or superblocks



