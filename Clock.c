// Standard C program of a digital clock using Functions and Structures
#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hour;
    int minutes;
    int seconds;
};

int main()
{
    int i;
    struct time timeUpdate (struct time now);
    struct time currentTime, nextTime;

    printf("Enter the current time in hh:mm:ss\n");
    printf("Make sure the hour is within 0-23, and the minute and second is within 0-59 each\n");
    scanf("%d:%d:%d",&currentTime.hour,&currentTime.minutes,&currentTime.seconds);

    if (currentTime.hour > 23 || currentTime.minutes > 59 || currentTime.seconds > 59)
    {
        printf("Wrong input\nERROR\n");
    }

    else
    {
        while (1) //While it is true i.e. infinite loop
        {
        system("clear"); // to clear the screen so that it doesn't print out a list of the time
        nextTime = timeUpdate(currentTime); //calling the function
        printf("%.2d:%.2d:%.2d\n",nextTime.hour,nextTime.minutes,nextTime.seconds);
        currentTime = nextTime;//for updating time in function 'timeUpdate'
        sleep(1);//waits 1 second to replay loop. Windows user need to add time in milliseconds. i.e sleep(1000) for 1 seconds.
        }
    }
    return 0;
}

//Function to update time
struct time timeUpdate (struct time now)
{
    now.seconds++;
    if(now.seconds == 60){
        now.seconds = 0;
        now.minutes++;
            if(now.minutes == 60){
                now.minutes = 0;
                now.hour++;
                    if (now.hour == 24)
                        now.hour = 0;
            }
    }
    return now;
}
