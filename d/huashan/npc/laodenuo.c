// laodenuo.c 

inherit NPC;

void create()
{
	set_name("�͵�ŵ", ({ "lao denuo", "lao", "denuo" }));
	set("nickname", "�Ϻ���");
	set("long", 
"�͵�ŵ��İ��֣������⣬����Ц���еģ�����\n"
"ͬ�������еڶ����ǻ�ɽ������һ����Ψһ����Ͷʦ�ġ�\n");
	set("gender", "����");
	set("age", 54);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 18);
	set("int", 25);
	set("con", 20);
	set("per", 20);
	
	set("max_kee", 1200);
	set("max_gin", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);
	set("combat_exp", 90000);
	set("score", 8000);

	set_skill("force", 60);
	set_skill("zixia-shengong", 60);
	set_skill("dodge", 60);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("strike", 80);
	set_skill("cuff", 80);
	set_skill("hunyuan-zhang", 80);
	set_skill("huashan-jianfa", 80);
	set_skill("huashan-shenfa", 60);
	set_skill("poyu-quan", 60);

	map_skill("dodge", "huashan-shenfa");
	map_skill("force", "zixia-shengong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");

//	prepare_skill("strike", "hunyuan-zhang");
//	prepare_skill("cuff", "poyu-quan");

	create_family("��ɽ��", 14, "����");

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/changjian")->wield();
}
