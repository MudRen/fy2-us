// shidaizi.c 

inherit NPC;

void create()
{
	set_name("ʩ����", ({ "shi daizi", "shi", "daizi" }));
	set("long", 
"ʩ������ĸ�������������ͨͨ����˫�۾�����������\n"
"ͬ�������е��ģ��ǻ�ɽ������һ���еĺ��֡�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("per", 28);
	
	set("max_kee", 850);
	set("max_gin", 650);
	set("force", 850);
	set("max_force", 850);
	set("force_factor", 20);
	set("combat_exp", 60000);
	set("score", 6000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 60);
	set_skill("sword", 65);
	set_skill("blade", 65);
	set_skill("strike", 60);
	set_skill("zixia-shengong", 50);
	set_skill("hunyuan-zhang", 60);
	set_skill("fanliangyi-dao", 60);
	set_skill("huashan-jianfa", 65);
	set_skill("huashan-shenfa", 50);

	map_skill("force", "zixia-shengong");
	map_skill("parry", "huashan-jianfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

//prepare_skill("strike", "hunyuan-zhang");
//prepare_skill("cuff", "poyu-quan");

	create_family("��ɽ��", 14, "����");

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/changjian")->wield();
}
