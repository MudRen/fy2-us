
inherit ITEM;

void create()
{
	set_name("ҹ����", ({ "pearl" , "ҹ����"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ں�ҹ���������ҹ���顣\n");
		set("value", 10000);
	}
}
