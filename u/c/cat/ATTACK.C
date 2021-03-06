// filename : /system/feature/attack.c

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

#define MAX_OPPONENT    8

static object duishou = 0;
static object *enemy = ({});
static string *bihua = ({});
static string *killer = ({});

///////////////////////////////////////////////////////////////////////////
// prototypes

object query_duishou() { return duishou; }
object *query_enemy() { return enemy; }
string *query_bihua() { return bihua; }
string *query_killer() { return killer; }

int remove_duishou(object ob);
int remove_enemy(object ob);
int remove_bihua(object ob);
int remove_killer(object ob);
void remove_all_duishou();
void remove_all_enemy();

///////////////////////////////////////////////////////////////////////////
// 状态判断函数

varargs int is_duilianing(object ob)
{
	if (( ob && ( ob == duishou )) || ( !ob && duishou ))
        return 1;
	return 0;
}

varargs int is_fighting(object ob)
{
	if ( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy) != -1;
}

varargs int is_bihuaing(string id)
{
	if ( !id ) return sizeof(bihua) > 0;

	return member_array(id, bihua) != -1;
}

varargs int is_killing(string id)
{
	if ( !id ) return sizeof(killer) > 0;

	return member_array(id, killer) != -1;
}


//这是下马用的
int do_ride_none(object me)
{

    object *inv,ob, thisa;
    int i = 0;
    
    if( !thisa = find_object( VOID_OB ) )
        thisa = load_object( VOID_OB );
    inv = all_inventory(thisa);
    while( i < sizeof(inv) && i >= 0 )
    {
        if( inv[i]->query("is_rided_by") == me->query("id") )
        {
            ob = inv[i];
            i = -10;
        }
        i++;    
    }
    if( i >= 0 )            
        return notify_fail("发现错误！\n");
    message_vision("$N急忙从$n上跳下迎战。\n", me, ob);
    ob->move( environment(me) );
    ob->delele("is_rided_by");
    ob->set("xingcheng", me->query_temp_marks("zuoji/xingcheng"));
    me->delete_temp_marks("is_riding");
    me->delete_temp_marks("zuoji");
    return 1;
}

void duilian_ob(object ob)
{
	if ( !ob || ob == this_object() ) return;

    delete_temp( "pending/duilian" );
	set_heart_beat( 1 );

    duishou = ob;
    if ( ob->query_temp_marks("is_riding") != 0 )
    {
        do_ride_none( ob );
    }
}


void fight_ob(object ob)
{
	if ( !ob || ob == this_object() ) return;

    delete_temp( "pending/fight" );
	set_heart_beat( 1 );

    if ( ob->is_lianing() )
    {
        ob->stop_lian();
        ob->set_busy( random( 3 ) );
        message_vision( HIY"$N赶紧收势迎战，忙了个手足无措！\n" NOR, ob );
    }
    else if ( ob->is_duilianing() )
    {
        ob->remove_all_duishou();
        ob->set_busy( random( 3 ) );
        message_vision( HIY"$N赶紧停手迎战，忙了个手足无措！\n" NOR, ob );
    }

    if ( ob->query_temp_marks("is_riding") != 0 && userp(ob) )
    {
        do_ride_none( ob );
        ob->set_busy( random( 3 ) );
    }
	if ( member_array( ob, enemy ) == -1 ) 
    	enemy += ({ ob });

    if (ob->is_fighting(this_object()))
        return;
    else
    {
        ob->fight_ob(this_object());
        return;
    }    
}

void bihua_ob(object ob)
{
	if ( member_array( ob->query( "id" ), bihua ) == -1 )
    	bihua += ({ ob->query( "id" ) });

    delete_temp( "pending/bihua" );
	fight_ob( ob );
}

void kill_ob(object ob)
{
	object *guards;

	if( member_array(ob->query("id"), killer)==-1 )
    	killer += ({ ob->query("id") });

	tell_object(ob, HIR "看起来" + this_object()->name() + "想杀死你！\n" NOR);

	if ( ob == query_temp( "guardfor" ) )
    {
    	delete_temp("guardfor");
    	guards = ob->query_temp("guarded");
    	guards -= ({ this_object() });
    	ob->set_temp("guarded", guards);
    	tell_object(this_object(), HIY "你停止保护" + ob->name() + "。\n" NOR);
    	tell_object(ob, HIY + this_object()->name() + "停止保护你。\n" NOR);
    }

	if ( arrayp(guards = ob->query_temp("guarded")) )
    {
    	guards = filter_array(guards, (:
            	objectp($1)
            &&	living($1)
            &&    $1 != this_object()
            &&	present($1, environment())
            &&    !is_fighting($1)
            &&    $1->visible(this_object()) :));
    	if ( sizeof(guards) > 0 )
        {
            enemy += guards;
        	message("vision", HIR + ob->name() + "受到攻击！你挺身加入战团！\n" NOR,
            	guards);
        	guards->kill_ob(this_object());
        }
    }
	fight_ob(ob);
}

///////////////////////////////////////////////////////////////////////////
// 战斗对象整理 

void clean_up_duishou()
{
	if ( objectp( duishou ) )
    {
        if (( environment( duishou ) != environment() ) ||
            !living( duishou ) )
        {
        	duishou = 0;
        }
    }
}

void clean_up_enemy()
{
	if ( sizeof( enemy ) > 0 )
    {
    	for ( int i = 0; i < sizeof( enemy ); i++ )
        {
        	object ob = enemy[ i ];

        	if ( !objectp( ob ) ||
                 environment( ob ) != environment() ||
                ( !living( ob ) && !is_killing( ob->query( "id" ) ) ) )
            {
            	enemy[ i ] = 0;
                if ( bihua  && objectp( ob ) )
                    bihua -= ({ ob->query( "id" ) });
            }
        }
    	enemy -= ({ 0 });
    }
}

int remove_duishou(object ob)
{
    if ( duishou && ( ob == duishou ))
    {
        duishou = 0;
        return 1;
    }
    return 0;
}

int remove_enemy(object ob)
{
	if ( is_killing( ob->query( "id" ) ) ) return 0;

	enemy -= ({ ob });
	return 1;
}

int remove_bihua(object ob)
{
	if ( is_bihuaing( ob->query( "id" ) ) )
    {
        if ( bihua )
        	bihua -= ({ ob->query( "id" ) });
    	remove_enemy( ob );
    	return 1;
    }

	return remove_enemy(ob);
}

int remove_killer(object ob)
{
	if ( is_killing( ob->query( "id" ) ) )
    {
    	killer -= ({ ob->query( "id" ) });
    	remove_enemy( ob );
    	return 1;
    }

	return remove_enemy(ob);
}

void remove_all_duishou()
{
    if ( objectp( duishou ) )
        duishou->remove_duishou( this_object() );
    duishou = 0;
}

void remove_all_enemy()
{
	for ( int i = 0; i < sizeof( enemy ); i++ )
    {
    	if ( objectp( enemy[ i ] ) )
        {
            if ( bihua )
                bihua -= ({ enemy[ i ]->query( "id" ) });
        	enemy[ i ]->remove_bihua( this_object() );
        }
    	enemy[ i ] = 0;;
    }

	enemy = ({});
}

void remove_all_killer()
{
	killer = ({});
	enemy -= ({ 0 });
    
	for ( int i = 0; i < sizeof( enemy ); i++ )
    	if ( enemy[ i ] )
        {
            if ( bihua )
                bihua -= ({ enemy[ i ]->query( "id" ) });
            enemy[ i ]->remove_killer( this_object() );
            enemy[ i ] = 0;
        }

	enemy -= ({ 0 });
}

///////////////////////////////////////////////////////////////////////////
// 战斗进行

object select_opponent()
{
	int which;

    if ( duishou ) return duishou;

	if ( !sizeof( enemy ) ) return 0;

	which = random( MAX_OPPONENT );

	return which < sizeof( enemy ) ? enemy[ which ] : enemy[ 0 ];
}

int attack()
{
	object opponent;

	clean_up_duishou();
	clean_up_enemy();

	opponent = select_opponent();
	if ( objectp( opponent ) )
    {
    	set_temp( "last_opponent", opponent );
    	COMBAT_D->fight( this_object(), opponent );
    	return 1;
    }
	else
    	return 0;
}

void init()
{
	object ob;
	string vendetta_mark;

	if ( is_fighting() ||
         !living( this_object() ) ||
         !( ob = this_player() ) ||
         environment( ob ) != environment() ||
         !living( ob ) ||
         ob->query( "linkdead" ) )
    {
    	return;
    }

	if ( userp( ob ) && is_killing( ob->query( "id" ) ) ) 
    {
    	COMBAT_D->auto_fight( this_object(), ob, "hatred" );
    	return;
    }
	else if ( random((int)query("bellicosity") / 40) > (int)query("cps") ) 
    {
    	COMBAT_D->auto_fight( this_object(), ob, "berserk" );
    	return;
    } 
}


