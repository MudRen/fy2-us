#include <weapon.h>
inherit DAGGER;
void create()
{
	set_name("������", ({ "order" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ��ذ�ס�\n");
                set("no_drop",1);
                set("no_get",1);
                set("owner","fengyun");
                set("rigidity",50);
		set("material", "steel");
	        set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
        	set("unwield_msg", "$N�����е�$n���뻳�С�\n");
	}
	init_dagger(5);
	setup();
}
