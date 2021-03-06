#include "mysql_func.hpp"
#include "optimization.hpp"
#include "glpk.h"
//#define EP
//#define FLAG
//#define IT
//#define UT
//#define VR
//#define PRICE
//#define LOAD_MODEL
//#define IT_final_result
using namespace std;
int main()
{

	MYSQL_FUNC mysql_func("140.124.42.65", "root", "fuzzy314", "Hems_lib");
	OPTIMIZE opt(mysql_func.ep, mysql_func.gpf, mysql_func.lpf);
	opt.get_IT(mysql_func.interrupt_load);
	opt.set_col(mysql_func.gpf, mysql_func.lpf);
	opt.set_obj(mysql_func.gpf, mysql_func.price);
	opt.set_situation(mysql_func.gpf, mysql_func.lpf);
	opt.load_matrix();
	opt.set_opt_parm();
	opt.update_final_result(mysql_func.gpf, mysql_func.lpf);
	opt.update_experiment_parameter();
	opt.outport_file();

	for (size_t i = 0; i < 12; i++)
	{
		cout << "IT" << i + 1 << " already operation time =" << opt.interrupt_load[i].already_op_time << " " << endl;
	}
	for (size_t i = 0; i < 12; i++)
	{
		cout << "IT" << i + 1 << " remain operation time =" << opt.interrupt_load[i].remain_op_time << " " << endl;
	}

#ifdef IT_final_result
	for (size_t i = 0; i < 12; i++)
	{
		cout << "IT = " << i + 1 << " " << opt.final_result->IT_switch[i][0] << " ";
		cout << endl;
	}
#endif

#ifdef IT

	for (size_t i = 0; i < 12; i++)
	{
		cout << "id = " << mysql_func.interrupt_load[i].id << " ";
		cout << "group_id = " << mysql_func.interrupt_load[i].group_id << " ";
		cout << "start_time = " << mysql_func.interrupt_load[i].start_time << " ";
		cout << "end_time = " << mysql_func.interrupt_load[i].end_time << " ";
		cout << "operation_time = " << mysql_func.interrupt_load[i].operation_time << " ";
		cout << "max_power = " << mysql_func.interrupt_load[i].max_power << " ";
		cout << "equip_name = " << mysql_func.interrupt_load[i].equip_name;
		cout << endl;
	}

	for (size_t i = 0; i < 12; i++)
	{
		cout << "id = " << opt.interrupt_load[i].id << " ";
		cout << "group_id = " << opt.interrupt_load[i].group_id << " ";
		cout << "start_time = " << opt.interrupt_load[i].start_time << " ";
		cout << "end_time = " << opt.interrupt_load[i].end_time << " ";
		cout << "operation_time = " << opt.interrupt_load[i].operation_time << " ";
		cout << "max_power = " << opt.interrupt_load[i].max_power << " ";
		cout << "equip_name = " << opt.interrupt_load[i].equip_name;
		cout << endl;
	}
#endif

#ifdef UT
	for (size_t i = 0; i < 2; i++)
	{
		cout << "id = " << mysql_func.uninterrupt_load[i].id << " ";
		cout << "group_id = " << mysql_func.uninterrupt_load[i].group_id << " ";
		cout << "start_time = " << mysql_func.uninterrupt_load[i].start_time << " ";
		cout << "end_time = " << mysql_func.uninterrupt_load[i].end_time << " ";
		cout << "operation_time = " << mysql_func.uninterrupt_load[i].operation_time << " ";
		cout << "max_power = " << mysql_func.uninterrupt_load[i].max_power << " ";
		cout << "equip_name = " << mysql_func.uninterrupt_load[i].equip_name;
		cout << endl;
	}

	for (size_t i = 0; i < 2; i++)
	{
		cout << "id = " << opt.uninterrupt_load[i].id << " ";
		cout << "group_id = " << opt.uninterrupt_load[i].group_id << " ";
		cout << "start_time = " << opt.uninterrupt_load[i].start_time << " ";
		cout << "end_time = " << opt.uninterrupt_load[i].end_time << " ";
		cout << "operation_time = " << opt.uninterrupt_load[i].operation_time << " ";
		cout << "max_power = " << opt.uninterrupt_load[i].max_power << " ";
		cout << "equip_name = " << opt.uninterrupt_load[i].equip_name;
		cout << endl;
	}
#endif

#ifdef VR
	for (size_t i = 0; i < 1; i++)
	{
		cout << "id = " << mysql_func.varying_load[i].id << " ";
		cout << "group_id = " << mysql_func.varying_load[i].group_id << " ";
		cout << "start_time = " << mysql_func.varying_load[i].start_time << " ";
		cout << "end_time = " << mysql_func.varying_load[i].end_time << " ";
		cout << "operation_time = " << mysql_func.varying_load[i].operation_time << " ";
		cout << "power_block[0] = " << mysql_func.varying_load[i].power_block[0] << " ";
		cout << "power_block[1] = " << mysql_func.varying_load[i].power_block[1] << " ";
		cout << "power_block[2] = " << mysql_func.varying_load[i].power_block[2] << " ";
		cout << "op_time_block[0] = " << mysql_func.varying_load[i].op_time_block[0] << " ";
		cout << "op_time_block[1] = " << mysql_func.varying_load[i].op_time_block[1] << " ";
		cout << "op_time_block[2] = " << mysql_func.varying_load[i].op_time_block[2] << " ";
		cout << "equip_name = " << mysql_func.varying_load[i].equip_name;
		cout << endl;
	}

	for (size_t i = 0; i < 1; i++)
	{
		cout << "id = " << opt.varying_load[i].id << " ";
		cout << "group_id = " << opt.varying_load[i].group_id << " ";
		cout << "start_time = " << opt.varying_load[i].start_time << " ";
		cout << "end_time = " << opt.varying_load[i].end_time << " ";
		cout << "operation_time = " << opt.varying_load[i].operation_time << " ";
		cout << "power_block[0] = " << opt.varying_load[i].power_block[0] << " ";
		cout << "power_block[1] = " << opt.varying_load[i].power_block[1] << " ";
		cout << "power_block[2] = " << opt.varying_load[i].power_block[2] << " ";
		cout << "op_time_block[0] = " << opt.varying_load[i].op_time_block[0] << " ";
		cout << "op_time_block[1] = " << opt.varying_load[i].op_time_block[1] << " ";
		cout << "op_time_block[2] = " << opt.varying_load[i].op_time_block[2] << " ";
		cout << "equip_name = " << opt.varying_load[i].equip_name;
		cout << endl;
	}
#endif

#ifdef EP
	cout << "realtime = " << mysql_func.ep.real_time << endl;
	cout << "ini_SOC = " << mysql_func.ep.ini_SOC << endl;
	cout << "now_SOC = " << mysql_func.ep.now_SOC << endl;
	cout << "P_bat_max = " << mysql_func.ep.P_bat_max << endl;
	cout << "P_bat_min = " << mysql_func.ep.P_bat_min << endl;
	cout << "P_grid_max = " << mysql_func.ep.P_grid_max << endl;
	cout << "simulate_price = " << mysql_func.ep.simulate_price << endl;
	cout << "SOC_max = " << mysql_func.ep.SOC_max << endl;
	cout << "SOC_min = " << mysql_func.ep.SOC_min << endl;
	cout << "SOC_threshold = " << mysql_func.ep.SOC_threshold << endl;
	cout << "time_block = " << mysql_func.ep.time_block << endl;
	cout << "vess_cess = " << mysql_func.ep.vess_cess << endl;
#endif

#ifdef FLAG
	cout << "Pgrid = " << mysql_func.pf.Pgrid << endl;
	cout << "Psell = " << mysql_func.pf.Sell << endl;
	cout << "Pess = " << mysql_func.pf.Pess << endl;
	cout << "SOC change = " << mysql_func.pf.SOC_change << endl;
	cout << "FC = " << mysql_func.pf.FC << endl;
	cout << "DR = " << mysql_func.pf.DR << endl;
	cout << "Comfort = " << mysql_func.pf.Comfort << endl;
	cout << "PV = " << mysql_func.pf.PV << endl;
#endif

#ifdef LOAD_MODEL
	mysql_func.get_load_model();
	for (size_t i = 0; i < mysql_func.load_model.size(); i++)
	{
		printf("load_model[%d] = %d\n", i, mysql_func.load_model[i]);
	}
#endif

#ifdef PRICE
	mysql_func.get_price();

	for (size_t i = 0; i < mysql_func.price.size(); i++)
	{
		printf("price[%d] = %f\n", i, mysql_func.price[i]);
	}
#endif

	return 0;
}
