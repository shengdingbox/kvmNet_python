# include <pybind11/pybind11.h>	 
#include "kmboxNet.h"
#pragma comment(lib, "ws2_32.lib")

namespace py = pybind11;
//其他函数
int kmNet_reboot(void);
int kmNet_debug(short port, char enable);



PYBIND11_MODULE(kmNet, m) {
m.doc() = "kmboxNet modules";   
m.def("init", &kmNet_init, "connect kmbox net box,you need input ip,port,uuid");
//鼠标类函数
m.def("move",   &kmNet_mouse_move,   "move mouse directory,input x,y");
m.def("left",   &kmNet_mouse_left,   "control mouse left button.  input 1=down ,0=up");
m.def("right",  &kmNet_mouse_right,  "control mouse right button. input 1=down ,0=up");
m.def("middle", &kmNet_mouse_middle, "control mouse middle button. input 1=down ,0=up");
m.def("wheel",  &kmNet_mouse_wheel,  "control mouse wheel.input >0 down,<0 up");
m.def("mouse",  &kmNet_mouse_all,    "control all mouse data.input button,x,y,wheel");
m.def("move_auto", &kmNet_mouse_move_auto, "move mouse auto.input x,y,time_ms");
m.def("move_beizer", &kmNet_mouse_move_beizer, "move mouse beizer.input x,y,time_ms,piont1_x,point1_y,point2_x,point2_y");

//键盘类函数
m.def("keydown", &kmNet_keydown, "set keyboard down .input vkey");
m.def("keyup",  &kmNet_keyup, "set keyboard down .input vkey");

//监控类函数
m.def("monitor", &kmNet_monitor, "monitor keyboard and mouse.");
m.def("isdown_left",   &kmNet_monitor_mouse_left, "check mouse left isdown?");
m.def("isdown_middle", &kmNet_monitor_mouse_middle, "check mouse middle isdown?");
m.def("isdown_right",  &kmNet_monitor_mouse_right,  "check mouse right isdown?");
m.def("isdown_side1", &kmNet_monitor_mouse_side1, "check mouse side1 isdown?");
m.def("isdown_side2", &kmNet_monitor_mouse_side2, "check mouse side1 isdown?");
m.def("isdown_keyboard", &kmNet_monitor_keyboard, "check keyborard vkey isdown?");

//屏蔽类函数
m.def("mask_left",	 &kmNet_mask_mouse_left,	"mask or unmask mouse left.");
m.def("mask_right",	 &kmNet_mask_mouse_right,	"mask or unmask mouse right.");
m.def("mask_middle", &kmNet_mask_mouse_middle,	"mask or unmask mouse middle.");
m.def("mask_side1",	 &kmNet_mask_mouse_side1,	"mask or unmask mouse side1.");
m.def("mask_side2",  &kmNet_mask_mouse_side2,	"mask or unmask mouse side2.");
m.def("mask_x",		 &kmNet_mask_mouse_x,		"mask or unmask mouse x.");
m.def("mask_y",      &kmNet_mask_mouse_y,       "mask or unmask mouse y.");
m.def("mask_wheel",  &kmNet_mask_mouse_wheel,   "mask or unmask mouse wheel.");
m.def("mask_keyboard",&kmNet_mask_keyboard,		"mask keyboard key.");
m.def("unmask_keyboard",&kmNet_unmask_keyboard,"unmask keyboard key.");
m.def("unmask_all",   &kmNet_unmask_all,		"unmask all.");

//配置类
m.def("reboot",		 &kmNet_reboot,		 "reboot kmbox net.");
m.def("setip_port",  &kmNet_setconfig,	 "set box ip and port.");
m.def("lcd_color",   &kmNet_lcd_color,	 "set lcd color.");
m.def("lcd_picture", &kmNet_lcd_picture, "set lcd picture.");
m.def("lcd_picture_bottom", &kmNet_lcd_picture_bottom, "set lcd picture half.");
}