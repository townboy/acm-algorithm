//1.2 A*
/*f() = g() + h()
h() 是估价函数，要求h(state)求出来的必须是理论值的下界，否则不能保证正确性，其次，越接近实际值越好。
*/
//1.3 IDA*
int deep;

bool ID(int d){
	int state = h();
	if(0 == state)
		return true;
	if(d + state > deep)
		return false;
	handle();
}

for(deep = 0; ;deep ++){
	if(true == ID(0))
		break;
}
cout << deep << endl;
