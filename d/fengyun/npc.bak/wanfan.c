// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����ߵ�", ({ "wanfan" }) );
        set("gender", "����" );
        set("age", 60);
        set("long",
                "һ���ú�����һ���;��ÿ��׵����̣�\n");
	set("combat_exp", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ߵĻ��˻����е���ߣ�Ц�����������ԣ���\n",
        }) );

        set("attitude", "friendly");
        set("vendor_goods", ([
                "С�糵": __DIR__"obj/windche",
		"���˶�" :__DIR__"obj/niren",
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{
        add_action("do_vendor_list", "list");
}

