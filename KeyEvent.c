#include"KeyEvent.h"
//模拟两个键的组合键事件
void KeybdEventBoth(int a,int b){
	//模拟按键事件详情
		/*https://www.codeleading.com/article/16143337113/#:~:text=%E5%A6%82%E4%BD%95%E6%A8%A1%E6%8B%9F%E6%8C%89%E9%94%AE%E6%93%8D%E4%BD%9C%EF%BC%9F,%E5%9C%A8C%2FC%2B%2B%E4%B9%8B%E4%B8%AD%EF%BC%8CWindows%E7%B3%BB%E7%BB%9F%E6%8F%90%E4%BE%9B%E4%BA%86%E6%A8%A1%E6%8B%9F%E9%94%AE%E7%9B%98%E6%93%8D%E4%BD%9C%E7%9A%84%E6%8E%A5%E5%8F%A3%EF%BC%8C%E4%BD%BF%E7%94%A8%E6%96%B9%E5%BC%8F%E4%B8%BAkeybd_event%E5%87%BD%E6%95%B0%EF%BC%8C%E6%9C%89%E5%85%B3keybd_event%E5%87%BD%E6%95%B0%E7%9A%84%E4%BD%BF%E7%94%A8%E5%A6%82%E4%B8%8B%E3%80%82*/
	keybd_event(a, 0, 0, 0);//按下ctrl键
	keybd_event(b, 0, 0, 0);//按下+键

	keybd_event(b, 0, KEYEVENTF_KEYUP, 0);//松开-键
	keybd_event(a, 0, KEYEVENTF_KEYUP, 0);//松开ctrl键


}