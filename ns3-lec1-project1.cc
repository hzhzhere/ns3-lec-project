#include "ns3/core-module.h"

#include <iostream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("HelloSimulator");

static void printHello(std::string name,std::string ID,float frequency) {
	std::cout<<Simulator::Now()<<" Hello "<<name<<" "<<ID<<std::endl;
	Simulator::Schedule(Seconds(frequency),&printHello,name,ID,frequency);
}
int main (int argc, char *argv[])
{
	CommandLine cmd;
	std::string name;
        std::string ID;
        float frequency123;
        //type in --frequency in commandline,frequency123 means you linked frequency to frequency123
	cmd.AddValue ("name", "here is the name", name);
        cmd.AddValue ("ID","type in the ID",ID);
        cmd.AddValue ("frequency","type in the frequency",frequency123);
	cmd.Parse(argc,argv);

	printHello(name,ID,frequency123);

	Simulator::Stop(Seconds(5));
	Simulator::Run ();
	Simulator::Destroy ();
}
