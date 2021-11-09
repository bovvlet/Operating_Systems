#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <linux/input-event-codes.h>

static int que[11];
static const char *const evval[3] = {"RELEASED", "PRESSED", "REPEATED"};

void push(int val){
    for(int i = 1; i < 10; i++)
        que[i - 1] = que[i];
    que[10] = val;
}

int main(void) {
	  struct input_event ev;
	  ssize_t n;

	  int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);

	  while(1 == 1)
	  {
	  	read(fd, &ev, sizeof ev);
	  	if(ev.type == EV_KEY && ev.value == 1)
		{
			push(ev.code);

			if (queue[N-1] == KEY_E && queue[N-2] == KEY_P)
				printf("I passed the Exam!\n");
			if (queue[N-1] == KEY_P && queue[N-2] == KEY_A && queue[N-3] == KEY_C)
				printf("Get some cappuccino!\n");
			else if(queue[N-1] == KEY_C && queue[N-2] == KEY_C && queue[N-3] == KEY_S && queue[N-4] == KEY_G)
		    		printf("Get some Cheese cake!\n");
		}
	  }

	  fflush(stdout);
	  fprintf(stderr, "%s \n", strerror(errno));
	  return -1;
}
