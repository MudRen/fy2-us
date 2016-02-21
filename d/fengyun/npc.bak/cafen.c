// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("��Ӣ", ({ "huying" }) );
	set("gender", "����" );
	set("title", "�ײĵ��ϰ�");
	set("age", 55);
	set("long",
		"��λ���˵����ϲ�����ƣ�����\n");
	set("combat_exp", 50);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		"ֽǮ": __DIR__"obj/zhiqian",
                "ֽ��": __DIR__"obj/zhihua",
		"�ҷ�ֽ": "/obj/paper_seal",
	]) );
	set_skill("unarmed",5);
	setup();
	carry_object("/obj/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N����$nһ�۵���ľ��û���������ˣ�̪�������ˡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N��$n�ʵ���˭���ˣ�\n",this_object(),ob);
                        break;
        }
}

