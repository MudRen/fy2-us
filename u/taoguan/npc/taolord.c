// taolord.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("���˷�", ({ "master ding", "master", "ding" }) );
        set("nickname", HIG"�̺��˷�" NOR);
        set("gender", "����");
        set("age", 47);
        set("long",
                
"���˷�ԭ�������������ң�����С��ѧ���ó������ķ���\n"
"���������ڴ˾��޳��ɽ�ħ֮����\n");

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
"�����幬������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n"
        ]) );

        set("apprentice_available", 3);
        create_family("���幬", 5, "����");

        set_skill("literate", 70);
        set_skill("magic", 40);
        set_skill("force", 30);
        set_skill("move", 40);
        set_skill("scratching", 200);
	set_skill("spells",50);
        set_skill("unarmed", 30);
        set_skill("sword", 100);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("gouyee", 60);
	set_skill("notracesnow", 100);
	set_skill("snowshade-sword", 100);

        set_skill("taoism", 100);
        set_skill("scratmancy", 100);
	set_skill("necromancy",50);

        map_skill("scratching", "scratmancy");
        map_skill("parry", "snowshade-sword");
        map_skill("sword", "snowshade-sword");
        map_skill("move", "notracesnow");
        map_skill("dodge", "notracesnow");



        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);
        setup();

        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/robe")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
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
        if( (string)ob->query("gender") != "����" )
                command("say ƶ���ǳ����ˣ�������Ůͽ�������ˡ�");
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
                student->set("title","���幬��ʿ");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","���幬С����");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","���幬����");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","���幬С��ʦ");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","���幬��ʦ");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","���幬����ʦ");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","���幬������");
                return ;
        } else
                student->set("title","���幬����");
                return ;
}
 
