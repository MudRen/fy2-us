// yuhuan.c ���� 

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("����", ({ "cheng yuhuan", "cheng", "yuhuan" }));
	set("long", 
		"�����ǳ�֪���Ķ���Ů���������绨����ò�����ɵĳ��񻷡�\n"
		"��˵���������䵱����ѧ��������\n");
		
	set("title", "֪��ǧ��");
	set("nickname", "���ɹ�");
	set("gender", "Ů��");
	set("age", 18);
	set("per",30);
	
	set("shen_type", 1);

	set("force", 400);
	set("max_force", 400);
	set("max_kee", 400);
	set("max_gin", 200);
	set("force_factor", 10);

	set_skill("force", 50);
	set_skill("unarmed", 40);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 40);
	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);

	setup();
	carry_object(__DIR__"obj/goldring")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
	carry_object(__DIR__"obj/pink_cloth")->wear();
	carry_object(__DIR__"obj/flower_shoe")->wear();
}
