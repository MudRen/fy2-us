// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������͵���̫��", ({ "taipo", "po" }) );
        set("long",
                "���Ƴ������ϵ���̫�ţ�������С����������\n");

	set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 0);
        setup();
        carry_object("obj/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_work", "work");

}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
message_vision("$N����Ĺ������ڽ����ˣ�����Ҳ�۵�Ҫ��\n",me);
me->add("gin",-30);
me->add("sen",-30);
ob = new("/obj/money/silver");
ob->move(me);
message_vision("������͵���̫�Ŷ�$N˵��������Ĺ�Ǯ��\n", me);
return 1;
}
