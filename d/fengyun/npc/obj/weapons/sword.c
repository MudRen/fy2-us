#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("������", ({ "order" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ���ɫ�ĳ������������ᡣ\n");
                set("no_drop",1);
                set("no_get",1);
                set("owner","fengyun");
                set("rigidity",300);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(30);
	setup();
}
