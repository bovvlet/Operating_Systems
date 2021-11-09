#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const ev_val[3] = {"RELEASED", "PRESSED", "REPEATED"};

int main(void) 
{
	struct input_event ev;
	ssize_t n;
	int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
	while(1 == 1)
	{
		n = read(fd, &ev, sizeof ev);
		if (n == (ssize_t)-1) 
		{
		    if (errno == EINTR)
			continue;
		    else
			break;
		} 
		else if(n != sizeof ev)
		{
		    errno = EIO;
		    break;
		}

		if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2)
		    printf("%s 0x%04x (%d)\n", ev_val[ev.value], (int)ev.code, (int)ev.code);
		
	}

  fflush(stdout);
  fprintf(stderr, "%s \n", strerror(errno));
  return -1;
}
