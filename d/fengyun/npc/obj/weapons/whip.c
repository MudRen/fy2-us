#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( "������", ({ "order" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_drop",1);
                set("no_get",1);
                set("owner","fengyun");
                set("rigidity",300);
                set("material", "skin");
	        set("wield_msg", "$N����������һ��$n�������С�\n");
        	set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        init_whip(30);
        setup();
}
