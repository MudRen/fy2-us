#include <weapon.h>
inherit AXE;
void create()
{
	set_name("������", ({ "order" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop",1);
		set("no_get",1);
		set("owner","fengyun");
		set("rigidity",300);
		set("material", "iron");
		set("long", "����һ�Ѻ����͵��������������ء�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�������䡣\n");
	}
	init_axe(30);
	setup();
}
