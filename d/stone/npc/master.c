// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("Ҷ�³�", ({ "master ye", "master", "master gucheng" }) );
        set("nickname", HIW "���Ƴ���"NOR);
        set("gender", "����" );
        set("age", 34);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 30);
	set("max_kee",99999999);
        set("max_gin",999999);
        set("max_sen",999999);
	set("eff_kee",999999);
	set("kee",999999);
        set("chat_chance", 1);
        set("chat_msg", ({
                "Ҷ�³Ǵӵ��Ѫ�ߵİ���˺��һ��������\nҶ�³��ôӵ��Ѫ�ߵİ���˺�µĲ������Լ����ˡ�\n",
        }) );

        set("long",
"
���Ƴ�����ǰ���������ٺ͹�ɣ������ڣ�����
��֪���Ǳ����Ű������˵��˿�����ȫ���ã�����
\n"
	);
        create_family("���Ƴ�", 2, "����");

        set("combat_exp", 100000000);
        set("score", 200000);

        set_skill("move", 100);
        set_skill("parry", 120);
        set_skill("dodge", 80);
        set_skill("force", 40);
        set_skill("literate", 60);
	set_skill("sword", 100);
	set_skill("unarmed",40);
	set_skill("changquan",100);
	set_skill("feixian-steps",100);
	set_skill("feixian-sword",150);
	set_skill("jingyiforce",60);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
	carry_object(__DIR__"obj/bcloth")->wear();

}

void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
void init()
{
        add_action("give_quest", "quest");
}
 
int accept_object(object who, object ob)
{
if(ob->query("name") == "�߲�˿�д�" && ob->query("realsilk"))
{
	command("say ���������ˣ������㻭ױ����ȥ�ɣ�\n");
	command("say �����书��΢��������\n");
	command("say �˹����µ��������ҵĺ��ѣ�Ҳ�����ɰ����㣮\n");
	who->set_temp("marks/ye",1);
	return 1;
}
return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","���Ƴǵ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","���Ƴ����");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","���Ƴ�С�ܼ�");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","���Ƴǹܼ�");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","���ƳǴ�ܼ�");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","���Ƴ��ܹ�");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","���ƳǴ��ܹ�");
                return ;
        } else
                student->set("title","���ƳǸ�����");
                return ;

}

