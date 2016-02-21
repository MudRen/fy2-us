inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
	set_name(HIY "�������" NOR, ({ "tianji", "Tian ji", "Tian" }) );

	set("gender", "����");
	set("age", 99);
	set("long",
		"�������������ף��׷�ͯ�ա��ڱ�������������һ��
�����Ϲ٣�С��֮�ϣ����������ͽ�����ޣ�������\n");
	set("attitude", "peaceful");
        set("skill_public",1);
	set("str", 26000);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������������̳��˼��ڣ�������\n",
        }) );

	set("force", 40000);
	set("max_force", 80000);
	set("force_factor", 1000);

	set("combat_exp", 10000000);
	set("score", 200000);

	set_skill("unarmed", 120);
	set_skill("force", 100);
	set_skill("iron-cloth", 100);
	set_skill("yiqiforce", 30);
	set_skill("dagger",200);
	set_temp("apply/attack",300);
	set_temp("apply/damage",30000);
	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");

	create_family("��ң��", 1, "��ʦ");
	set("title", "����Ұ��");
	setup();

	carry_object(__DIR__"obj/jade-ring")->wear();
	carry_object(__DIR__"obj/jade-pin")->wear();
	carry_object(__DIR__"obj/jade-boots")->wear();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
}
int accept_fight(object me)
{
        command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
}
int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
	string test;
	mapping quest;
	val = ob->value();
	if (val && val >10000 && val < 20000)
	{
		       who->set("quest", 0 );
       	 	tell_object(who,"�������˵�����ðɣ������������˰ɣ���\n");
		who->delete_temp("quest_number");
		return 1;
	}
        if(!(quest =  who->query("quest")))
	{
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
	return 0;
	}
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"�������˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                        return 1;
        }
        else
        {
        tell_object(who,"�������˵������ϲ�㣡���������һ������\n");
	exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+1;
// put a cap
	if(exp > 150) exp = 150;
	exp = exp * (int) who->query_temp("quest_number");
	pot = exp / 5 + 1;
//	due to weekly quest, each quet worth 20
//	score = quest["score"]/2 + random(quest["score"]/2);
	score = 1;
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("score",score);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ��\n" +
	chinese_number(score)+"���ۺ�����\n"NOR);
	who->set("quest", 0 );
                        return 1;
        }
                return 1;
}
void attempt_apprentice(object me)
{
	switch(random(4)) {
		case 0:
message_vision("$N��$nЦ�ʵ���ʲô���Ľ���\n", this_object(),me);
			break;
		case 1:
message_vision("$N��$nЦ�ʵ���ʲô�ǣ��в������Ҳ�������һ�������ȶ�����\n", this_object(),me);	
			break;
		case 2:
message_vision("$N��$nЦ�ʵ��������Σ����Σ���ʲô��\n", this_object(),me);		
			break;
		case 3:
message_vision("$N��$nЦ�ʵ�����ѧ����߾�����ʲô��\n", this_object(),me);
			break;
	}
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}

