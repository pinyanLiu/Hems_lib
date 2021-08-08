#include "mysql_func.hpp"
using namespace std;
int main(){

MYSQL_FUNC mysql_func("140.124.42.65","root", "fuzzy314", "chig");
//import.ep = import.get_experimental_parameters();
mysql_func.get_experimental_parameters();
//testing

cout<<"realtime = "<<mysql_func.ep.real_time<<endl;
cout<<"ini_SOC = "<<mysql_func.ep.ini_SOC<<endl;
cout<<"now_SOC = "<<mysql_func.ep.now_SOC<<endl;
cout<<"P_bat_max = "<<mysql_func.ep.P_bat_max<<endl;
cout<<"P_bat_min = "<<mysql_func.ep.P_bat_min<<endl;
cout<<"P_grid_max = "<<mysql_func.ep.P_grid_max<<endl;
cout<<"simulate_price = "<<mysql_func.ep.simulate_price<<endl;
cout<<"SOC_max = "<<mysql_func.ep.SOC_max<<endl;
cout<<"SOC_min = "<<mysql_func.ep.SOC_min<<endl;
cout<<"SOC_threshold = "<<mysql_func.ep.SOC_threshold<<endl;
cout<<"time_block = "<<mysql_func.ep.time_block<<endl;
cout<<"vess_cess = "<<mysql_func.ep.vess_cess<<endl;

mysql_func.get_plan_flag();

cout<<"Pgrid = "<<mysql_func.pf.Pgrid<<endl;
cout<<"Psell = "<<mysql_func.pf.Psell<<endl;
cout<<"SOC = "<<mysql_func.pf.SOC<<endl;
cout<<"SOC change = "<<mysql_func.pf.SOC_change<<endl;
cout<<"mu_fc = "<<mysql_func.pf.mu_fc<<endl;
cout<<"mu_gird = "<<mysql_func.pf.mu_grid<<endl;
cout<<"Pess = "<<mysql_func.pf.Pess<<endl;
cout<<"Pfc = "<<mysql_func.pf.Pfc<<endl;




return 0;
}