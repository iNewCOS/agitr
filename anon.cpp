#include <ros/ros.h>

int main(int argc, char ** argv){
	ros::init(argc,argv,"anon",ros::init_options::AnonymousName);
	ros::NodeHandle nh;
	ros::Rate rate(1);

	while(ros::ok()){
		ROS_INFO_STREAM("This message is from" 
			<< ros::this_node::getName());
		rate.sleep();
	}	
}