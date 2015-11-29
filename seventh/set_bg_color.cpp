//this program waits for a turtlesim to start up, and
// changes its background color.

#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "set_bg_color");
	ros::NodeHandle nh;

	ros::service::waitForService("clear");

	ros::param::set("background_r", 255);
	ros::param::set("background_g", 255);
	ros::param::set("background_b", 0 );

	ros::ServiceClient clearClient = 
		nh.serviceClient<std_srvs::Empty>("/clear");
		std_srvs::Empty srv;
		clearClient.call(srv);
}