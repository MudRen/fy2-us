
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("�����", ({ "zhuge" }) );
	set("gender", "����" );
	set("age", 31);
	set("title", HIG "���罣" NOR);
	set("long",
		"��ʨ�ھֵĴ���ͷ���ֵ��»����ԣ�\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                "����": "/obj/weapon/whip",
                "����": "/obj/weapon/longsword",
                "����": "/obj/weapon/dart",
                "ţƤ��": "/obj/weapon/shield",
                "�˽Ǵ�": "/obj/weapon/eighthammer",
                "ϸ��": "/obj/weapon/thin_sword",
                "ذ��": "/obj/weapon/dagger.c",
               "����": "/obj/weapon/blade.c",
		"����" : __DIR__"obj/1staff.c",
                "�ɵ�" : __DIR__"obj/knife.c",
               "˫��" : __DIR__"obj/dual_ring.c",
	]) );
	set_skill("sword",50);
	set_skill("six-chaos-sword",50);
	set_skill("pyrobat-steps",50);
	set_skill("dodge",50);
	set_skill("parry",50);
	map_skill("dodge","pyrobat-steps");
	map_skill("parry", "six-chaos-sword");
	map_skill("sword","six-chaos-sword");
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object("/obj/longsword")->wield();
}
void init()
{
        add_action("do_vendor_list", "list");
}

