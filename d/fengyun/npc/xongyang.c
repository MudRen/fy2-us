
inherit NPC;

void create()
{
        set_name("������", ({ "guo", "yang"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�������������ĸ��֣���������û��������\n");
	set("title", "��������");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 90);
	set_skill("dodge", 100);
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
}

