// taolord.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name( "������" , ({ "master ding", "master", "ding" }) );
        set("nickname",HIB "��հ���" NOR);
        set("gender", "Ů��");
        set("age", 46);
        set("long",
                
"�������Ƕ��˷��ʦ�ã�Ҳ�Ƕ��˷�������á�����������ʱ�������������\n"
"�����������������ɱ�˰�����󵽴˳��ҡ�\n");

        set("combat_exp", 10000000);
        set("score", 200000);

        set("class", "taoist");

        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);

        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 30);

        set("atman", 1400);
        set("max_atman", 1400);

        set("mana", 4000);
        set("max_mana", 2000);
        set("mana_factor", 5);

        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
                "���幬": 
"��éɽ��������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n"
        ]) );

        set("apprentice_available", 3);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("���幬", 6, "Ů����");

        set_skill("literate", 70);
        set_skill("magic", 40);
        set_skill("force", 30);
        set_skill("spells", 200);
	set_skill("scratching",50);
	set_skill("move", 40);
        set_skill("unarmed", 30);
        set_skill("sword", 100);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("gouyee", 100);
        set_skill("notracesnow", 100);
        set_skill("snowshade-sword", 80);

        set_skill("taoism", 100);
        set_skill("necromancy", 100);
	set_skill("scratmancy",50);

        map_skill("spells", "necromancy");
        map_skill("parry", "snowshade-sword");
        map_skill("sword", "snowshade-sword");
        map_skill("move", "notracesnow");
        map_skill("dodge", "notracesnow");


        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);

        setup();

        carry_object(__DIR__"obj/sword2")->wield();
        carry_object(__DIR__"obj/robe2")->wear();
        carry_object(__DIR__"obj/hat2")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ƶ�������Ѿ������������ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
                command("say ƶ���ǳ����ˣ���������ͽ�������ˡ�");
        else {
                command("say ��... ���������幬��Ҳ��....");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
        add("apprentice_availavble", -1);
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
                student->set("title","���幬���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","���幬Сʦ̫");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","���幬ʦ̫");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","���幬ʥ��");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","���幬����");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","���幬����");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","���幬������");
                return ;
        } else
                student->set("title","���幬����");
                return ;

}
