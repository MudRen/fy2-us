
inherit ITEM;
void create()
{
	string *name=({"��","��","Ͱ"});
	string *num = ({"һ","��","��","��","��","��","��","��","��"});
	set_name( num[random(9)]+name[random(3)] , ({ "majiangpai"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ���µ������齫��\n");
		set("unit", "��");
		set("value", 30000);
	}
	setup();
}
