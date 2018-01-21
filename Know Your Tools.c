
void write_random(int fd, ssize_t num_bytes) {
  reset_file(fd);
  char *buffer;
  for (; num_bytes > 0; num_bytes -= PAGE_SIZE) {
    ssize_t string_size = min(PAGE_SIZE, num_bytes + 1);
    buffer = random_string(string_size);
    write(fd,buffer,string_size);
    lseek(fd,0, SEEK_CUR);
    free(buffer);  
    }
  return;
}
