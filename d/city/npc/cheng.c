// cheng.c ��ҩ��

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("��ҩ��", ({ "cheng yaofa", "cheng" }));
	set("title", "����֪��");
	set("gender", "����");
	set("age", 43);
	set("str", 20);
	set("per", 20);
	set("long", "�����ǳ�ҩ������������֪����\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("force", 500); 
	set("max_force", 500);
	set("force_factor", 10);

	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object("/obj/cloth")->wear();
}
