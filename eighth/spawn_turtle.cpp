//This program spawns a new turtlesim turtle by calling
// the appropriate service.
#include <ros/ros.h>
//The srv class for the service.
#include <turtlesim/Spawn.h>

int main(int argc, char **argv){

	ros::init(argc, argv, "spawn_turtle");
	ros::NodeHandle nh;

//Create a client object for the spawn service. This
//needs to know the data type of the service and its name.
	ros::ServiceClient spawnClient
		= nh.serviceClient<turtlesim::Spawn>("spawn");

//Create the request and response objects.
turtlesim::Spawn::Request req;
turtlesim::Spawn::Response resp;

req.x = 2;
req.y = 3;
req.theta = M_PI/2;
req.name = "Leo";

bool success = spawnClient.call(req,resp);

if(success){
	ROS_INFO_STREAM("Spawned a turtle named "
			<< resp.name);
}else{
	ROS_ERROR_STREAM("Failed to spawn.");
}


}
