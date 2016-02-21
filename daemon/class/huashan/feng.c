// feng.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
//	set("nickname", "��ʦ��");
	set("long", 
"�����ǻ�ɽ���ڵĳ��Ϸ�����������ݳ���ü���һֱ������һ�ɵ���������\n"
"��ɫ����Ȼ�Ե���Ľ�������֮��һֱ����������\n");
	set("gender", "����");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("per", 30);
	
	set("kee", 4800);
	set("max_kee", 4800);
	set("gin", 3600);
	set("max_gin", 3600);
	set("force", 4400);
	set("max_force", 4400);
	set("force_factor", 200);

	set("combat_exp", 1750000);
	set("score", 200000);

	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 220);
	set_skill("strike", 200);
	set_skill("zixia-shengong", 150);
	set_skill("poyu-quan", 170);
	set_skill("fanliangyi-dao", 180);
	set_skill("huashan-jianfa", 200);
	set_skill("hunyuan-zhang", 170);
	set_skill("dugu-jiujian", 200);
	set_skill("huashan-shenfa",160);
	set_skill("literate", 120);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "dugu-jiujian");
	map_skill("sword", "dugu-jiujian");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("��ɽ��", 12, "����");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.poqi" :),
//		(: perform_action, "sword.pozhang" :),
//		(: perform_action, "sword.pojian" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	int student_num;
	string temp;
	string line;

	temp = read_file("/daemon/class/huashan/FENG", 1, 1);
	student_num = atoi(temp);

	line = "������˵�����������ڹ���" + temp + "��ͽ�ܡ���\n";
	write(line);

	if ( student_num == 3)
	{
		command("say �������ˣ����Ѿ���������ͽ���ˡ�");
		return;
	}

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "��ɽ��")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������������أ�");
		return;
	}

	if (((int)ob->query_skill("sword",1) < 150) || ((int)ob->query_skill("huashan-jianfa",1) < 150))
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ļ�ɽ������ûѧ���Ұɡ�");
		return;
	}
	if (((int)ob->query_skill("force",1) < 150) || ((int)ob->query_skill("zixia-shengong",1) < 130))
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "����ϼ�񹦻�ûѧ���Ұɡ�");
		return;
	}
	if (((int)ob->query_skill("dodge",1) < 150) || ((int)ob->query_skill("huashan-shenfa",1) < 150))
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ļ�ɽ������ûѧ���Ұɡ�");
		return;
	}
	if ( (int)ob->query_skill("literate",1) < 160)
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ķ���ʶ�ֻ�ûѧ���Ұɡ�");
		return;
	}

	if ((int)ob->query("shen") < 100000)
	{
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}

	if ((int)ob->query_int() < 41) {
		command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�Ҷ��¾Ž���");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	student_num++;
//	temp = itoa(student_num);
	if(student_num == 1)
		temp = "1";
	else if(student_num == 2)
		temp = "2";
	else if(student_num == 3)
		temp = "3";
	write_file("/daemon/class/huashan/FENG", temp, 1);
}