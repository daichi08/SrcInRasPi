//for LRF
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
//for UDP
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "udp_pub");
  ros::NodeHandle n;
  ros::Subscriber sub;
  ros::Rate loop_rate(10);
  int sock;
  struct sockaddr_in addr;

  sock = socket(AF_INET, SOCK_DGRAM, 0);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = inet_addr("169.254.170.171");

  sendto(sock, "HELLO", 5, 0, (struct sockaddr *)&addr, sizeof(addr));

  close(sock);

 return 0;
}
