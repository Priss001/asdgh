#include <time.h>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

int main()
{
initscr();
time_t t;
tm* tm;
pid_t pid;
refresh();
pid=fork();
switch(pid)
	{	
		case -1:
			throw ("Error");
			break;
		case 0:
			sleep(5);
			t=time(NULL);
			tm=localtime(&t);
			printw("CD: %s", asctime(tm));
			refresh();

			break;
		default:
			t=time(NULL);
			tm=localtime(&t);
			printw("Per: %s", asctime(tm));
			refresh();

			break;
	}
refresh();
getch();
endwin();
return 0;
}