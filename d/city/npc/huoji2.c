// huoji. ҩ�̻��

inherit NPC;
inherit F_VENDOR;
//inherit F_DEALER;

void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "��ʮ��ǿ׳������ȥ�Ἰ���书����ҩ�������ƺ������ں���\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/jinchuang",
		__DIR__"obj/yangjing",
	}));

	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
