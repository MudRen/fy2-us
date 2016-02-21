// lingshan.c 

inherit NPC;

void create()
{
	set_name("����ɺ", ({ "yue lingshan", "yue", "lingshan" }));
	set("nickname", "Сʦ��");
	set("long", 
"����ɺ��Ľ�С�����Ļ�����ò��һ��Ҳ������һ�������ˣ�����\n"
"ͬ�������е��ߣ��ǻ�ɽ����������Ⱥ�Ķ�Ů��\n");
	set("gender", "Ů��");
	set("age", 19);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("per", 28);
	
	set("max_kee", 600);
	set("max_gin", 500);
	set("force", 600);
	set("max_force", 500);
	set("force_factor", 10);
	set("combat_exp", 30000);
	set("score", 5000);

	set_skill("force", 30);
	set_skill("zixia-shengong", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("blade", 40);
	set_skill("strike", 50);
	set_skill("hunyuan-zhang", 50);
	set_skill("huashan-jianfa", 50);
	set_skill("huashan-shenfa", 50);
	set_skill("fanliangyi-dao", 30);
//	set_skill("chongling-jianfa", 50);

	map_skill("force", "zixia-shengong");
	map_skill("blade", "fanliangyi-dao");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");

//	prepare_skill("strike", "hunyuan-zhang");
//	prepare_skill("cuff", "poyu-quan");

	create_family("��ɽ��", 14, "����");

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/d/huashan/obj/bishuijian")->wield();
}
