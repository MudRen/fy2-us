
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("���촸", ({ "master lan", "lan","master" }) );
	set("gender", "����" );
        set("title",HIB "��������" NOR);
	set("age", 45);
	set("int", 30);
	set("str",700);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("�촸ɽׯ", 1, "ׯ��");
	set("long",
		"���촸��һ�����õĳ����뻯������
ÿ�궼�͵�����������һս���½�ʤ�����֣� 
���촸��Ƣ�������һ𣬾�����Ե�޹ʵĽ����Ӵ�����˻����ǽ�ţ�\n"
		);
        set("force_factor", 60);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("skill_public",1);
        set("chat_chance", 1);
        set("chat_msg", ({
"���촸Ц�����������϶����ֺ�������ʤ����\n",
        }) );
        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("hammer", 150);
        set_skill("force", 200);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("pangu-hammer", 150);
	set_skill("pofeng-strike", 120);
	set_skill("putiforce", 50);
	set_skill("nodust-steps", 100);

	map_skill("unarmed", "pofeng-strike");
        map_skill("hammer", "pangu-hammer");
        map_skill("force", "putiforce");
        map_skill("parry", "pangu-hammer");
        map_skill("dodge", "nodust-steps");
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.kaitianpidi" :),
        }) );
	setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/jumbohammer")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 4);
	set("try", random(10)+1);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ��ׯ�������Ѿ������ĸ����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
	if((int)ob->query_temp("xiao_failed") )
        {
        command("laugh");
	if( !random(10) && !ob->query("lan_failed")){
        command("say ���϶������㣿�ã��Ϸ�Ҳ�����㣬���������������ѧ��\n");
        ob->set("marks/lan",1);
	}
	else
	{
        command("say ���϶������㣿��������ľ���ɵ�Ҳ��������\n");
	ob->set("lan_failed",1);
	}
	return;
        }
        else {

                command("say ���պ���д�ɣ�");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lishi");
        add("apprentice_availavble", -1);
}

int recognize_apprentice(object ob)
{
        if( (string) ob->query("class") == "lishi")
		return 1;
        if( ob->query("marks/lan") )
	{
		if( !random(10)) {
		command("say �Ϸ�������鲻�ã��㻹���߰ɣ�����");
		ob->set("marks/lan",0);
		return 0;
		}
		return 1;
	}
        return 0;
}

void init()
{
        add_action("give_quest", "quest");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","�촸�ɵ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","�촸��С��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","�촸������");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","�촸�ɴ���");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","�촸������");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","�촸�ɳ���");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","�촸��Ԫ��");
                return ;
        } else
                student->set("title","�촸�ɸ�����");
                return ;
}

