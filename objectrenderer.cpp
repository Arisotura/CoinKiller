#include "objectrenderer.h"
#include "objects.h"

#include <QPainter>

SpriteRenderer::SpriteRenderer(const Sprite *spr, Tileset *tilesets[])
{
    this->spr = spr;

    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    switch (spr->getid()) {
    case 3: // Cheep Chomp
        ret = new NormalImageRenderer(spr, basePath + "cheep_chomp.png");
        break;
    case 8: // Swoop
        ret = new NormalImageRenderer(spr, basePath + "swoop.png");
        break;
    case 9: // Whomp
        ret = new NormalImageRenderer(spr, basePath + "whomp.png");
        break;
    case 18: // Tile God
        ret = new TileGodRenderer(spr, tilesets[0]);
        break;
    case 19: // Desert Crater
        ret = new NormalImageRenderer(spr, basePath + "desert_crater.png");
        break;
    case 20: // Gold Block
        ret = new NormalImageRenderer(spr, basePath + "gold_block.png");
        break;
    case 21: // Note Block
        ret = new NormalImageRenderer(spr, basePath + "note_block.png");
        break;
    case 22: // Special Exit Controller
        ret = new SpecialExitControllerRenderer(spr);
        break;
    case 27: // POW Block
        ret = new NormalImageRenderer(spr, basePath + "pow_block.png");
        break;
    case 28: // Movement Controlled POW Block
        ret = new NormalImageRenderer(spr, basePath +"pow_block.png");
        break;
    case 29: // Bob-omb
        ret = new NormalImageRenderer(spr, basePath + "bob-omb.png");
        break;
    case 31: // Boomerang Bro.
        ret = new NormalImageRenderer(spr, basePath + "boomerang_bro.png");
        break;
    case 32: // Fire Bro.
        ret = new NormalImageRenderer(spr, basePath + "fire_bro.png");
        break;
    case 33: // Hammer Bro.
        ret = new NormalImageRenderer(spr, basePath + "hammer_bro.png");
        break;
    case 35: // Lava Bubble
        ret = new NormalImageRenderer(spr, basePath + "lava_bubble.png");
        break;
    case 38: // Reznor Wheel
        ret = new ReznorWheelRenderer(spr);
        break;
    case 39: // Reznor Battle Dissapearing Blocks
        ret = new ReznorBlockRenderer(spr);
        break;
    case 52: // Checkpoint Flag
        ret = new NormalImageRenderer(spr, basePath + "checkpoint_flag.png");
        break;
    case 55: // Coin
        ret = new NormalImageRenderer(spr, basePath + "coin.png");
        break;
    case 66: // Pipe Cannon
        ret = new NormalImageRenderer(spr, basePath + "pipe_cannon.png");
        break;
    case 67: // Pipe Cannon - Ludwig Bossfight
        ret = new NormalImageRenderer(spr, basePath + "pipe_cannon_ludwig.png");
        break;
    case 69: // Door
        ret = new NormalImageRenderer(spr, basePath + "door.png");
        break;
    case 70: // Castle Boss Door
        ret = new NormalImageRenderer(spr, basePath + "door_castle_boss.png");
        break;
    case 71: // Closed Door
        ret = new NormalImageRenderer(spr, basePath + "door_closed.png");
        break;
    case 72: // Final Boss Door
        ret = new NormalImageRenderer(spr, basePath + "door_final_boss.png");
        break;
    case 73: // Ghost House Door
        ret = new NormalImageRenderer(spr, basePath + "door_ghosthouse.png");
        break;
    case 75: // Tower Boss Door
        ret = new NormalImageRenderer(spr, basePath + "door_tower.png");
        break;
    case 76: // Big Thwomp
        ret = new NormalImageRenderer(spr, basePath + "big_thwomp.png");
        break;
    case 77: // Thwomp
        ret = new NormalImageRenderer(spr, basePath + "thwomp.png");
        break;
    case 81: // Fireball Pipe - ! Junction
        ret = new NormalImageRenderer(spr, basePath + "fireballpipe_junction.png");
        break;
    case 83: // Fish Bone
        ret = new NormalImageRenderer(spr, basePath + "fish_bone.png");
        break;
    case 84: // Flag Controller - Chainer
        ret = new FlagRenderer(spr);
        break;
    case 85: // Flag Controller - IF
        ret = new FlagRenderer(spr);
        break;
    case 86: // Flag Controller - Zone enter
        ret = new FlagRenderer(spr);
        break;
    case 87: // Flag Controller - Multi Chainer
        ret = new FlagRenderer(spr);
        break;
    case 88: // Flag Controller - On screen
        ret = new FlagRenderer(spr);
        break;
    case 92: // Grinder
        ret = new NormalImageRenderer(spr, basePath + "grinder.png");
        break;
    case 94: // Flipper (One way gate)
        ret = new FlipperRenderer(spr);
        break;
    case 93: // Scuttlebug
        ret = new NormalImageRenderer(spr, basePath + "scuttlebug.png");
        break;
    case 95: // Blooper
        ret = new NormalImageRenderer(spr, basePath + "blooper.png");
        break;
    case 97: // End of Level Flag
        ret = new GoalRenderer(spr);
        break;
    case 99: // Wiggler
        ret = new NormalImageRenderer(spr, basePath + "wiggler.png");
        break;
    case 100: // Rotation Controlled ? Block
        ret = new ItemBlockRenderer(spr, basePath + "question_block");
        break;
    case 101: // Movement Controlled ? Block
        ret = new ItemBlockRenderer(spr, basePath + "question_block");
        break;
    case 106: // Trampoline
        ret = new NormalImageRenderer(spr, basePath + "trampoline.png");
        break;
    case 108: // Spider Web
        ret = new NormalImageRenderer(spr, basePath + "spider_web.png");
        break;
    case 109: // Signboard
        ret = new SignboardRenderer(spr);
        break;
    case 110: // Dry Bones
        ret = new NormalImageRenderer(spr, basePath + "dry_bones.png");
        break;
    case 111: // Giant Dry Bones
        ret = new NormalImageRenderer(spr, basePath + "giant_dry_bones.png");
        break;
    case 114: // Floating Box
        ret = new FloatingBoxRenderer(spr);
        break;
    case 115: // Floating Box
        ret = new BulletBillLauncherRenderer(spr);
        break;
    case 117: // Banzi Bill Launcher
        ret = new NormalImageRenderer(spr, basePath + "banzai_bill_launcher.png");
        break;
    case 120: // Up Down Mushroom
        ret = new UpDownMushroomRenderer(spr, basePath + "up_down_mushroom/");
        break;
    case 123: // Bouncy Mushroom
        ret = new BouncyMushroomRenderer(spr);
        break;
    case 124: // Mushroom Platform
        ret = new MushroomPlatformRenderer(spr, basePath + "mushroom_platform/");
        break;
    case 125: // Bowser
        ret = new NormalImageRenderer(spr, basePath + "bowser.png");
        break;
    case 135: // Goomba
        ret = new GoombaRenderer(spr);
        break;
    case 136: // Bone Goomba
        ret = new BoneGoombaRenderer(spr);
        break;
    case 137: // Micro Goomba
        ret = new NormalImageRenderer(spr, basePath + "micro_goomba.png");
        break;
    case 138: // Paragoomba
        ret = new NormalImageRenderer(spr, basePath + "paragoomba.png");
        break;
    case 139: // Goomba Tower
        ret = new GoombaTowerRenderer(spr);
        break;
    case 140: // Crowber
        ret = new NormalImageRenderer(spr, basePath + "crowber.png");
        break;
    case 143: // Conveyor Belt Switch
        ret = new NormalImageRenderer(spr, basePath + "conveyor_belt_switch.png");
        break;
    case 147: // 3 Plat rickshaw
        ret = new ThreePlatRickRenderer(spr);
        break;
    case 148: //Move While On Lift
        ret = new NormalImageRenderer(spr, basePath + "move_while_on_lift.png");
        break;
    case 150: // Seesaw Lift
        ret = new NormalImageRenderer(spr, basePath + "seesaw_lift.png");
        break;
    case 154: // 3 Plat rickshaw
        ret = new FourPlatRickRenderer(spr);
        break;
    case 158: // Buzzy Beetle
        ret = new NormalImageRenderer(spr, basePath + "buzzy_beetle.png");
        break;
    case 165: // Koopa Troopa
        ret = new KoopaTroopaRenderer(spr);
        break;
    case 167: // Pipe Piranha Plant - Down
        ret = new NormalImageRenderer(spr, basePath + "piranha_pipe_down.png");
        break;
    case 172: // Pipe bone Piranha Plant - Up
        ret = new NormalImageRenderer(spr, basePath + "bone_piranha_pipe_up.png");
        break;
    case 173: // Pipe Bone Piranha Plant - Left
        ret = new NormalImageRenderer(spr, basePath + "bone_piranha_pipe_left.png");
        break;
    case 174: // Pipe Bone Piranha Plant - Right
        ret = new NormalImageRenderer(spr, basePath + "bone_piranha_pipe_right.png");
        break;
    case 175: // Grounded Piranha Plant
        ret = new NormalImageRenderer(spr, basePath + "piranha_plant.png");
        break;
    case 176: // Big Grounded Pirahna Plant
        ret = new SwitchRenderer(spr, basePath + "big_piranha_plant.png");
        break;
    case 179: // Grounded Bone Piranha Plant
        ret = new NormalImageRenderer(spr, basePath + "bone_piranha_plant.png");
        break;
    case 180: // Big Grounded Bone Pirahna Plant
        ret = new SwitchRenderer(spr, basePath + "big_bone_piranha_plant.png");
        break;
    case 181: // Pipe Piranha Plant - Left
        ret = new NormalImageRenderer(spr, basePath + "piranha_pipe_left.png");
        break;
    case 182: // Pipe Piranha Plant - Right
        ret = new NormalImageRenderer(spr, basePath + "piranha_pipe_right.png");
        break;
    case 183: // Pipe Piranha Plant - Up
        ret = new NormalImageRenderer(spr, basePath + "piranha_pipe_up.png");
        break;
    case 184: // Parabomb
        ret = new NormalImageRenderer(spr, basePath + "parabomb.png");
        break;
    case 185: // Koopa Paratroopa
        ret = new KoopaParatroopaRenderer(spr);
        break;
    case 189: // Rectangle Lift - Tower
        ret = new RecLiftRenderer(spr, basePath + "tower_rectangle_lift/");
        break;
    case 190: // Rectangle Lift - Ghosthouse (Checkered)
        ret = new RecLiftRenderer(spr, basePath + "checkered_rectangle_lift/");
        break;
    case 191: // Rectangle Lift - Desert
        ret = new RecLiftRenderer(spr, basePath + "desert_rectangle_lift/");
        break;
    case 192: // Rectangle Lift - Castle
        ret = new RecLiftRenderer(spr, basePath + "castle_rectangle_lift/");
        break;
    case 193: // Rectangle Lift - Underwater
        ret = new RecLiftRenderer(spr, basePath + "underwater_rectangle_lift/");
        break;
    case 194: // Cheep Cheep
        ret = new NormalImageRenderer(spr, basePath + "cheep_cheep.png");
        break;
    case 195: // Big Cheep Cheep
        ret = new NormalImageRenderer(spr, basePath + "big_cheep_cheep.png");
        break;
    case 200: // Spiny Cheep Cheep
        ret = new NormalImageRenderer(spr, basePath + "spiny_cheep_cheep.png");
        break;
    case 203: // Rotation Controlled Brick Block
        ret = new ItemBlockRenderer(spr, basePath + "brick_block");
        break;
    case 204: // Movement Controlled Brick Block
        ret = new ItemBlockRenderer(spr, basePath + "brick_block");
        break;
    case 205: // Red Ring
        ret = new NormalImageRenderer(spr, basePath + "red_ring.png");
        break;
    case 206: // Gold Ring
        ret = new NormalImageRenderer(spr, basePath + "gold_ring.png");
        break;
    case 211: // Roy Koopa
        ret = new NormalImageRenderer(spr, basePath + "boss_roy.png");
        break;
    case 215: // Bob-omb Cannon
        ret = new BobOmbCannonRenderer(spr);
        break;
    case 216: // Boss Shutter
        ret = new NormalImageRenderer(spr, basePath + "boss_shutter.png");
        break;
    case 219: // Star Coin
        ret = new NormalImageRenderer(spr, basePath + "star_coin.png");
        break;
    case 221: // ! Switch
        ret = new SwitchRenderer(spr, basePath + "exclamation_switch.png");
        break;
    case 222: // Brick Block Contaning ! Switch
        ret = new NormalImageRenderer(spr, basePath + "brick_block_exclamation_switch.png");
        break;
    case 223: // ? Switch
        ret = new SwitchRenderer(spr, basePath + "question_switch.png");
        break;
    case 224: // Brick Block Contaning ? Switch
        ret = new NormalImageRenderer(spr, basePath + "brick_block_question_switch.png");
        break;
    case 225: // P Switch
        ret = new SwitchRenderer(spr, basePath + "p_switch.png");
        break;
    case 226: // Brick Block Contaning P Switch
        ret = new NormalImageRenderer(spr, basePath + "brick_block_p_switch.png");
        break;
    case 227: // Floating Barrel
        ret = new NormalImageRenderer(spr, basePath + "barrel.png");
        break;
    case 228: // Boo
        ret = new NormalImageRenderer(spr, basePath + "boo.png");
        break;
    case 229: // Big Boo
        ret = new NormalImageRenderer(spr, basePath + "big_boo.png");
        break;
    case 234: // Spiked Ball
        ret = new NormalImageRenderer(spr, basePath + "spiked_ball.png");
        break;
    case 235: // Big Spiked Ball
        ret = new NormalImageRenderer(spr, basePath + "big_spiked_ball.png");
        break;
    case 236: // Mega Spiked Ball
        ret = new NormalImageRenderer(spr, basePath + "mega_spiked_ball.png");
        break;
    case 240: // Urchin
        ret = new UrchinRenderer(spr);
        break;
    case 244: // Chain Chomp
        ret = new ChainChompRenderer(spr);
        break;
    case 251: // Treasure Chest
        ret = new NormalImageRenderer(spr, basePath + "treasure_chest.png");
        break;
    case 255: // Bowser Head Statue
        ret = new NormalImageRenderer(spr, basePath + "bowser_head_statue.png");
        break;
    case 260: // Tower Cutscene Roy
        ret = new NormalImageRenderer(spr, basePath + "roy_cutscene.png");
        break;
    case 261: // Tower Cutscene Iggy
        ret = new NormalImageRenderer(spr, basePath + "iggy_cutscene.png");
        break;
    case 262: // Tower Cutscene Wendy
        ret = new NormalImageRenderer(spr, basePath + "wendy_cutscene.png");
        break;
    case 263: // Tower Cutscene Morton
        ret = new NormalImageRenderer(spr, basePath + "morton_cutscene.png");
        break;
    case 264: // Tower Cutscene Ludwig
        ret = new NormalImageRenderer(spr, basePath + "ludwig_cutscene.png");
        break;
    case 265: // Tower Cutscene No koopa
        ret = new NormalImageRenderer(spr, basePath + "tower_cutscene.png");
        break;
    case 267: // Long Question Block
        ret = new ItemBlockRenderer(spr, basePath + "long_question_block.png");
        break;
    case 269: // Gold Ship
        ret = new NormalImageRenderer(spr, basePath + "gold_ship.png");
        break;
    case 270: // Icy Spiked Ball
        ret = new NormalImageRenderer(spr, basePath + "icy_spiked_ball.png");
        break;
    case 273: // Coin Roulette Block
        ret = new NormalImageRenderer(spr, basePath + "coin_roulette_block.png");
        break;
    case 274: // Flying Gold Block Spawn Point
        ret = new NormalImageRenderer(spr, basePath + "flying_gold_block.png");
        break;
    case 275: // Long Question Block - Underground
        ret = new ItemBlockRenderer(spr, basePath + "long_question_block_underground.png");
        break;
    case 276: // Long Question Block - Lava
        ret = new ItemBlockRenderer(spr, basePath + "long_question_block_lava.png");
        break;
    case 277: // Switchable Conveyor Belt
        ret = new NormalImageRenderer(spr, basePath + "switchable_conveyor_belt.png");
        break;
    case 278: // Assist Block
        ret = new NormalImageRenderer(spr, basePath + "assist_block.png");
        break;
    case 279: // Lemmy Ball
        ret = new NormalImageRenderer(spr, basePath + "lemmy_ball.png");
        break;
    case 280: // + Clock
        ret = new ClockRenderer(spr);
        break;
    case 287: // Toad House Door
        ret = new NormalImageRenderer(spr, basePath + "door_toadhouse.png");
        break;
    case 289: // Bouncy Mushroom Platform - Castle
        ret = new NormalImageRenderer(spr, basePath + "bouncy_mushroom_castle.png");
        break;
    case 293: // Punching Glove
        ret = new NormalImageRenderer(spr, basePath + "punching_glove.png");
        break;
    case 294: // Warp Cannon
        ret = new NormalImageRenderer(spr, basePath + "warp_cannon.png");
        break;
    case 296: // Toad
        ret = new NormalImageRenderer(spr, basePath + "toad.png");
        break;
    case 302: // Moon Coin
        ret = new NormalImageRenderer(spr, basePath + "moon_coin.png");
        break;
    case 314: // Ruins Rickshaw
        ret = new RuinsRickRenderer(spr);
        break;
    case 322: // Big Grinder
        ret = new NormalImageRenderer(spr, basePath + "big_grinder.png");
        break;
    default:
        ret = new RoundedRectRenderer(spr, QString("%1").arg(spr->getid()), QColor(0,90,150,150));
        break;

    }
}

void SpriteRenderer::render(QPainter *painter, QRect *drawrect)
{
    ret->render(painter, drawrect);
}

NormalImageRenderer::NormalImageRenderer(const Object *obj, QString filename)
{
    rect = QRect(obj->getx()+obj->getOffsetX(), obj->gety()+obj->getOffsetY(), obj->getwidth(), obj->getheight());
    this->filename = filename;
}

NormalImageRenderer::NormalImageRenderer(QRect rect, QString filename)
{
    this->rect = rect;
    this->filename = filename;
}

void NormalImageRenderer::render(QPainter *painter, QRect *)
{
    painter->drawPixmap(rect, QPixmap(filename));
}


RoundedRectRenderer::RoundedRectRenderer(const Object *obj, QString text, QColor color, QTextOption align)
{
    this->obj = obj;
    this->text = text;
    this->color = color;
    this->align = align;
}

void RoundedRectRenderer::render(QPainter *painter, QRect *)
{
    QRect rect(obj->getx()+obj->getOffsetX(), obj->gety()+obj->getOffsetY(), obj->getwidth(), obj->getheight());

    painter->setPen(QColor(0,0,0));

    QPainterPath path;
    path.addRoundedRect(rect, 2.0, 2.0);
    painter->fillPath(path, color);
    painter->drawPath(path);

    painter->setFont(QFont("Arial", 7, QFont::Normal));
    painter->drawText(rect, text, align);
}


// Sprite Renderers

// Sprite 18: Tile God
TileGodRenderer::TileGodRenderer(const Sprite *spr, Tileset *tileset)
{
    this->spr = spr;
    this->tileset = tileset;
}

void TileGodRenderer::render(QPainter *painter, QRect *)
{
    QRect sprrect(spr->getx(), spr->gety(), spr->getwidth(), spr->getheight());

    if ((spr->getNybble(7) % 2) == 0)
    {
        QBrush b(Qt::BDiagPattern);
        b.setColor(QColor(25, 25, 25));

        painter->fillRect(sprrect, b);

        painter->setPen(QPen(Qt::black));
    }

    else
    {
        if (tileset == NULL)
            painter->fillRect(sprrect, QColor(200, 0, 0, 120));
        else
        {
            QPixmap pix(spr->getwidth(), spr->getheight());
            pix.fill(QColor(0,0,0,0));
            QPainter tempPainter(&pix);

            TileGrid tileGrid;
            tileGrid[0xFFFFFFFF] = 1;

            tempPainter.setOpacity(0.5);

            int tileId = tileIds[0];

            if (spr->getNybble(6) < 12)
                tileId = tileIds[spr->getNybble(6)];


            for (int x = 0; x < spr->getwidth()/20; x++)
                for (int y = 0; y < spr->getheight()/20; y++)
                    tileset->drawTile(tempPainter, tileGrid, tileId, x, y, 1, 0);

            painter->drawPixmap(spr->getx(), spr->gety(), spr->getwidth(), spr->getheight(), pix);
        }
    }

    painter->drawRect(sprrect);
}

// Sprite 22: Special Exit Controller
SpecialExitControllerRenderer::SpecialExitControllerRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void SpecialExitControllerRenderer::render(QPainter *painter, QRect *)
{
    QRect sprRect(spr->getx(), spr->gety(), spr->getwidth(), spr->getheight());
    painter->fillRect(sprRect, QColor(0,255,0,30));
    painter->setPen(Qt::green);
    painter->drawRect(sprRect);
    painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", 8, QFont::Normal));
    painter->drawText(sprRect.adjusted(2,2,15,0), "Warp");
}

// Sprite 38: Reznor Wheel
ReznorWheelRenderer::ReznorWheelRenderer(const Sprite *spr)
{
    this->spr = spr;
}
void ReznorWheelRenderer::render(QPainter *painter, QRect *drawrect)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if(spr->getNybble(6) == 1)
        painter->drawPixmap(spr->getx()+spr->getOffsetX(),spr->gety()+spr->getOffsetY(),349, 353, QPixmap(basePath + "reznor_wheel_big.png"));
    else
    {
        painter->drawPixmap(spr->getx()+spr->getOffsetX(),spr->gety()+spr->getOffsetY(),201, 177, QPixmap(basePath + "reznor_wheel.png"));

        if(spr->getNybble(5) == 1) // Top Right
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+145,spr->gety()+spr->getOffsetY()-10,48, 55, QPixmap(basePath + "reznor.png"));
        if(spr->getNybble(5) == 2) // Top Left
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+35,spr->gety()+spr->getOffsetY()-40,48, 55, QPixmap(basePath + "reznor.png"));
        if(spr->getNybble(5) == 3) // Top Left + Top Right
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+145,spr->gety()+spr->getOffsetY()-10,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+35,spr->gety()+spr->getOffsetY()-40,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 4) // Bottom Left
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+5,spr->gety()+spr->getOffsetY()+71,48, 55, QPixmap(basePath + "reznor.png"));
        if(spr->getNybble(5) == 5) // Bottom Left + Top Right
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+5,spr->gety()+spr->getOffsetY()+71,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+145,spr->gety()+spr->getOffsetY()-10,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 6) // Bottom Left + Top Left
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+5,spr->gety()+spr->getOffsetY()+71,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+35,spr->gety()+spr->getOffsetY()-40,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 7) // Bottom Left + Top Left + Top Right
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+5,spr->gety()+spr->getOffsetY()+71,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+35,spr->gety()+spr->getOffsetY()-40,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+145,spr->gety()+spr->getOffsetY()-10,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 8) // Bottom Right
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+115,spr->gety()+spr->getOffsetY()+100,48, 55, QPixmap(basePath + "reznor.png"));
        if(spr->getNybble(5) == 9) // Top Right + Bottom Right
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+145,spr->gety()+spr->getOffsetY()-10,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+115,spr->gety()+spr->getOffsetY()+100,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 10) // Top Left + Bottom Right
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+35,spr->gety()+spr->getOffsetY()-40,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+115,spr->gety()+spr->getOffsetY()+100,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 11) // Top Left + Top Right + Bottom Right
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+35,spr->gety()+spr->getOffsetY()-40,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+145,spr->gety()+spr->getOffsetY()-10,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+115,spr->gety()+spr->getOffsetY()+100,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 12) // Bottom Left + Bottom Right
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+5,spr->gety()+spr->getOffsetY()+71,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+115,spr->gety()+spr->getOffsetY()+100,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 13) // Bottom Left + Bottom Right + Top Right
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+5,spr->gety()+spr->getOffsetY()+71,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+115,spr->gety()+spr->getOffsetY()+100,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+145,spr->gety()+spr->getOffsetY()-10,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 14) // Bottom Left + Bottom Right + Top Left
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+5,spr->gety()+spr->getOffsetY()+71,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+115,spr->gety()+spr->getOffsetY()+100,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+35,spr->gety()+spr->getOffsetY()-40,48, 55, QPixmap(basePath + "reznor.png"));
        }
        if(spr->getNybble(5) == 15) // All
        {
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+5,spr->gety()+spr->getOffsetY()+71,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+115,spr->gety()+spr->getOffsetY()+100,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+35,spr->gety()+spr->getOffsetY()-40,48, 55, QPixmap(basePath + "reznor.png"));
            painter->drawPixmap(spr->getx()+spr->getOffsetX()+145,spr->gety()+spr->getOffsetY()-10,48, 55, QPixmap(basePath + "reznor.png"));
        }
    }
}

// Sprite 39: Reznor Battle Disapearing Blocks
ReznorBlockRenderer::ReznorBlockRenderer(const Sprite *spr)
{
    this->spr = spr;
}
void ReznorBlockRenderer::render(QPainter *painter, QRect *drawrect)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if(spr->getNybble(4) == 0)
        painter->drawPixmap(spr->getx(), spr->gety(), 20, 20, QPixmap(basePath + "reznor_platform.png"));
    for (int i = 0; i < spr->getNybble(4); i++)
        painter->drawPixmap(spr->getx()+spr->getOffsetX()+i*20, spr->gety(), 20, 20, QPixmap(basePath + "reznor_platform.png"));
}

// Sprite 84/85/86/87/88: Flags
FlagRenderer::FlagRenderer(const Sprite *spr)
{
    this->spr = spr;

    this->rect = new RoundedRectRenderer(spr, "", QColor(243,156,18,150));
}
void FlagRenderer::render(QPainter *painter, QRect *drawrect)
{
    rect->render(painter, drawrect);
    QRect textRect(spr->getx()+2, spr->gety()+1, 16, 20);

    if(spr->getid() == 84) // Chainer
    {
        painter->drawText(textRect, "F", Qt::AlignLeft | Qt::AlignTop);
        painter->setFont(QFont("Arial", 7, QFont::Thin));
        painter->drawText(textRect, QString("Cha"), Qt::AlignLeft | Qt::AlignBottom);
    }
    else if(spr->getid() == 85) // Location
    {
        painter->drawText(textRect, "F", Qt::AlignLeft | Qt::AlignTop);
        painter->setFont(QFont("Arial", 7, QFont::Normal));
        painter->drawText(textRect, QString("Loc"), Qt::AlignLeft | Qt::AlignBottom);
    }
    else if(spr->getid() == 86) // Zone Enter
    {
        painter->drawText(textRect, "F", Qt::AlignLeft | Qt::AlignTop);
        painter->setFont(QFont("Arial", 7, QFont::Normal));
        painter->drawText(textRect, QString("Zon"), Qt::AlignLeft | Qt::AlignBottom);
    }
    else if(spr->getid() == 87) // Multi Chaner
    {
        painter->drawText(textRect, "F", Qt::AlignLeft | Qt::AlignTop);
        painter->setFont(QFont("Arial", 7, QFont::Normal));
        painter->drawText(textRect, QString("Mch"), Qt::AlignLeft | Qt::AlignBottom);
    }
    else // Onscreen
    {
        painter->drawText(textRect, "F", Qt::AlignLeft | Qt::AlignTop);
        painter->setFont(QFont("Arial", 7, QFont::Normal));
        painter->drawText(textRect, QString("Ons"), Qt::AlignLeft | Qt::AlignBottom);
    }
}

// Sprite 94: Flipper (One Way Gate)
FlipperRenderer::FlipperRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "Flipper_Left_Down.png");
    else if (spr->getNybble(5) == 2) img = new NormalImageRenderer(spr, basePath + "Flipper_Right_Up.png");
    else if (spr->getNybble(5) == 3) img = new NormalImageRenderer(spr, basePath + "Flipper_Left_Up.png");
    else if (spr->getNybble(5) == 4) img = new NormalImageRenderer(spr, basePath + "Flipper_Up_Left.png");
    else if (spr->getNybble(5) == 5) img = new NormalImageRenderer(spr, basePath + "Flipper_Down_Left.png");
    else if (spr->getNybble(5) == 6) img = new NormalImageRenderer(spr, basePath + "Flipper_Up_Right.png");
    else if (spr->getNybble(5) == 7) img = new NormalImageRenderer(spr, basePath + "Flipper_Down_Right.png");
    else img = new NormalImageRenderer(spr, basePath + "Flipper_Right_Down.png");
}

void FlipperRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}

// Sprite 97: End of Level Flag
GoalRenderer::GoalRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(10) == 1)
    {
        pole = new NormalImageRenderer(spr, basePath + "flagpole_secret.png");
        fort = new NormalImageRenderer(QRect(spr->getx()+200, spr->gety()+80, 120, 120), basePath + "castle_secret.png");
    }
    else
    {
        pole = new NormalImageRenderer(spr, basePath + "flagpole.png");
        fort = new NormalImageRenderer(QRect(spr->getx()+200, spr->gety()+80, 120, 120), basePath + "castle.png");
    }
}

void GoalRenderer::render(QPainter *painter, QRect *drawrect)
{
    pole->render(painter, drawrect);
    fort->render(painter, drawrect);
}

// Sprite 109: Signboard
SignboardRenderer::SignboardRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");
    QString signboardPath("sign_%1");

    if (spr->getNybble(5) < 10) img = new NormalImageRenderer(spr, basePath + signboardPath.arg(spr->getNybble(5)));
    else img = new NormalImageRenderer(spr, basePath + signboardPath.arg(7));
}

void SignboardRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}


// Sprite 114: Floating Box
FloatingBoxRenderer::FloatingBoxRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "floating_box_big.png");
    else img = new NormalImageRenderer(spr, basePath + "floating_box_small.png");
}

void FloatingBoxRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}


// Sprite 115: Bullet Bill Launcher
BulletBillLauncherRenderer::BulletBillLauncherRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void BulletBillLauncherRenderer::render(QPainter *painter, QRect *)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(10) == 1)
    {
        painter->drawPixmap(spr->getx(), spr->gety()+spr->getheight()-40, 20, 40, QPixmap(basePath + "bullet_bill_launcher_flipped.png"));
        for (int i = 0; i < spr->getNybble(4); i++) painter->drawPixmap(spr->getx(), spr->gety()+i*20, 20, 20, QPixmap(basePath + "bullet_bill_launcher_middle.png"));
    }
    else
    {
        painter->drawPixmap(spr->getx(), spr->gety()+spr->getOffsetY(), 20, 40, QPixmap(basePath + "bullet_bill_launcher.png"));
        for (int i = 0; i < spr->getNybble(4); i++) painter->drawPixmap(spr->getx(), spr->gety()+spr->getOffsetY()+40+i*20, 20, 20, QPixmap(basePath + "bullet_bill_launcher_middle.png"));
    }
}

// Sprite 120: Up-Down Mushroom
UpDownMushroomRenderer::UpDownMushroomRenderer(const Sprite *spr, QString basePath)
{
    this->spr = spr;
    this->basePath = basePath;
}

void UpDownMushroomRenderer::render(QPainter *painter, QRect *)
{
    QString color;
    if((spr->getNybble(7)) < (spr->getNybble(4)))
        color = "blue";
    else
        color = "pink";

    for (int i = 0; i < spr->getNybble(4); i++)
        painter->drawPixmap(QRect(spr->getx(), spr->gety()+spr->getOffsetY()+20+i*20, 20, 30), QPixmap(basePath + "stem.png"));
    painter->drawPixmap(QRect(spr->getx()+spr->getOffsetX(), spr->gety(), 30, 30), QPixmap(basePath + color + "_l.png"));
    painter->drawPixmap(QRect(spr->getx()-spr->getOffsetX()-10, spr->gety(), 30, 30), QPixmap(basePath + color + "_r.png"));
    for (int i = 30; i < spr->getwidth()-30; i += 20)
        painter->drawPixmap(QRect(spr->getx()+spr->getOffsetX()+i, spr->gety(), 20, 30), QPixmap(basePath + color + "_m.png"));
}

// Sprite 123: Bouncy Mushroom
BouncyMushroomRenderer::BouncyMushroomRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void BouncyMushroomRenderer::render(QPainter *painter, QRect *)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(15) == 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "bouncy_mushroom_big.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "bouncy_mushroom.png"));
}


// Sprite 124: Mushroom Platform Renderer
MushroomPlatformRenderer::MushroomPlatformRenderer(const Sprite *spr, QString basePath)
{
    this->spr = spr;
    this->basePath = basePath;
}

void MushroomPlatformRenderer::render(QPainter *painter, QRect *)
{
    painter->drawPixmap(QRect(spr->getx()+spr->getOffsetX(), spr->gety(), 24, 20), QPixmap(basePath + "l.png"));
    painter->drawPixmap(QRect(spr->getx()-spr->getOffsetX()-24, spr->gety(), 24, 20), QPixmap(basePath + "r.png"));
    for (int i = 24; i < spr->getwidth()-24; i += 20)
        painter->drawPixmap(QRect(spr->getx()+spr->getOffsetX()+i, spr->gety(), 20, 20), QPixmap(basePath + "m.png"));
}


// Sprite 135: Goomba
GoombaRenderer::GoombaRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void GoombaRenderer::render(QPainter *painter, QRect *)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(14) % 2 == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "goomba.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "goomba_blue.png"));
}


// Sprite 136: Bone Goomba
BoneGoombaRenderer::BoneGoombaRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void BoneGoombaRenderer::render(QPainter *painter, QRect *)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(14) % 2 == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "bone_goomba.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "bone_goomba_alt.png"));
}


// Sprite 139: Goomba Tower
GoombaTowerRenderer::GoombaTowerRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    top = new NormalImageRenderer(QRect(spr->getx(), spr->gety()+spr->getOffsetY(), spr->getwidth(), 25), basePath + "goomba_tower_top.png");
    bottom = new NormalImageRenderer(QRect(spr->getx(), spr->gety(), spr->getwidth(), 21), basePath + "goomba_tower_bottom.png");

    if (spr->getNybble(5) < 3) return;
    for (int i = 0; i < spr->getNybble(5)-2; i++) middle.append(new NormalImageRenderer(QRect(spr->getx(), spr->gety()+spr->getOffsetY()+25+i*21, spr->getwidth(), 21), basePath + "goomba_tower_middle.png"));
}

void GoombaTowerRenderer::render(QPainter *painter, QRect *drawrect)
{
    top->render(painter, drawrect);
    for(int i = 0; i < middle.size(); i++) middle[i]->render(painter, drawrect);
    bottom->render(painter, drawrect);
}


// Sprite 147: 3 Plat Rickshaw
ThreePlatRickRenderer::ThreePlatRickRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "3Plat_Rickshaw_Big.png");
    else img = new NormalImageRenderer(spr, basePath + "3Plat_Rickshaw.png");
}

void ThreePlatRickRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}


// Sprite 154: 4 Plat Rickshaw
FourPlatRickRenderer::FourPlatRickRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "4Plat_Rickshaw.png");
    else img = new NormalImageRenderer(spr, basePath + "4Plat_Rickshaw_Big.png");
}

void FourPlatRickRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}


// Sprite 165: Koopa Troopa
KoopaTroopaRenderer::KoopaTroopaRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "koopa_troopa_red.png");
    else img = new NormalImageRenderer(spr, basePath + "koopa_troopa_green.png");
}

void KoopaTroopaRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}

// Sprite 185: Koopa Paratroopa
KoopaParatroopaRenderer::KoopaParatroopaRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "koopa_paratroopa_red.png");
    else img = new NormalImageRenderer(spr, basePath + "koopa_paratroopa_green.png");
}

void KoopaParatroopaRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}


// Sprite 176/180/221/223/225: Switches/Grounded Piranha plants
SwitchRenderer::SwitchRenderer(const Sprite *spr, QString filename)
{
    this->filename = filename;
    if (spr->getNybble(5) == 1) filename.insert(filename.size()-4, "_flipped");

    img = new NormalImageRenderer(spr, filename);
}

void SwitchRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}


// RecLiftRenderer
RecLiftRenderer::RecLiftRenderer(const Sprite *spr, QString path)
{
    this->spr = spr;
    this->path = path;
    if (spr->getid() == 192) sideOffset = 3;
}
void RecLiftRenderer::render(QPainter *painter, QRect *)
{
    int blockWidth = spr->getNybble(15) > 0 ? spr->getNybble(15)*20 : 20;
    int blockHeight = spr->getNybble(13) > 0 ? spr->getNybble(13)*20 : 20;

    painter->drawPixmap(QRect(spr->getx()-sideOffset, spr->gety(), 20+sideOffset, 20), QPixmap(path + "tl.png"));
    painter->drawPixmap(QRect(spr->getx()-sideOffset, spr->gety()+blockHeight, 20+sideOffset, 20), QPixmap(path + "bl.png"));
    painter->drawPixmap(QRect(spr->getx()+blockWidth, spr->gety(), 20+sideOffset, 20), QPixmap(path + "tr.png"));
    painter->drawPixmap(QRect(spr->getx()+blockWidth, spr->gety()+blockHeight, 20+sideOffset, 20), QPixmap(path + "br.png"));

    for (int i = 0; i < spr->getNybble(15)-1; i++)
    {
        painter->drawPixmap(QRect(spr->getx() + i*20+20, spr->gety(), 20, 20), QPixmap(path + "t.png"));
        painter->drawPixmap(QRect(spr->getx() + i*20+20, spr->gety()+blockHeight, 20, 20), QPixmap(path + "b.png"));
    }
    for (int i = 0; i < spr->getNybble(13)-1; i++)
    {
        painter->drawPixmap(QRect(spr->getx(), spr->gety() + i*20+20, 20, 20), QPixmap(path + "l.png"));
        painter->drawPixmap(QRect(spr->getx()+blockWidth, spr->gety() + i*20+20, 20, 20), QPixmap(path + "r.png"));
    }
    for (int x = 20; x < blockWidth; x+=20)
        for (int y = 20; y < blockHeight; y+=20)
            painter->drawPixmap(QRect(spr->getx()+x, spr->gety()+y, 20, 20), QPixmap(path + "c.png"));
    if (spr->getNybble(9) == 1 || spr->getNybble(9) == 3) for (int x = 0; x < blockWidth+20; x+=20) painter->drawPixmap(QRect(spr->getx()+x, spr->gety()-20, 20, 20), QPixmap(path + "s_t.png"));
    if (spr->getNybble(9) == 2 || spr->getNybble(9) == 3) for (int x = 0; x < blockWidth+20; x+=20) painter->drawPixmap(QRect(spr->getx()+x, spr->gety()+blockHeight+20, 20, 20), QPixmap(path + "s_b.png"));
    if (spr->getNybble(9) == 4 || spr->getNybble(9) == 6) for (int y = 0; y < blockHeight+20; y+=20) painter->drawPixmap(QRect(spr->getx()-20, spr->gety()+y, 20, 20), QPixmap(path + "s_l.png"));
    if (spr->getNybble(9) == 5 || spr->getNybble(9) == 6) for (int y = 0; y < blockHeight+20; y+=20) painter->drawPixmap(QRect(spr->getx()+blockWidth+20, spr->gety()+y, 20, 20), QPixmap(path + "s_r.png"));
}


// Sprite 215: Bob-omb Cannon
BobOmbCannonRenderer::BobOmbCannonRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void BobOmbCannonRenderer::render(QPainter *painter, QRect *)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) != 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "cannon_right.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "cannon_left.png"));
}


// Sprite 240: Urchin
UrchinRenderer::UrchinRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void UrchinRenderer::render(QPainter *painter, QRect *)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) != 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "urchin.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "urchin_big.png"));
}


// Sprite 244: Chain Chomp
ChainChompRenderer::ChainChompRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void ChainChompRenderer::render(QPainter *painter, QRect *)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5)%2 == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "chain_chomp_3.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "chain_chomp_1.png"));
}

// Sprites 100/101/203/204/267/275/276: Item Blocks
ItemBlockRenderer::ItemBlockRenderer(const Sprite *spr, QString filename)
{
    this->spr = spr;
    block = new NormalImageRenderer(spr, filename);
}

void ItemBlockRenderer::render(QPainter *painter, QRect *drawrect)
{
    block->render(painter, drawrect);

    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/tileoverlays/");
    QString overlay;

    switch (spr->getNybble(13))
    {
        case 1: overlay = "coin.png"; break;
        case 2: overlay = "fire_flower.png"; break;
        case 4: overlay = "super_leaf.png"; break;
        case 5: overlay = "gold_flower.png"; break;
        case 6: overlay = "mini_mushroom.png"; break;
        case 7: overlay = "super_star.png"; break;
        case 8: overlay = "coin_star.png"; break;
        case 10: overlay = "10_coins.png"; break;
        case 11: overlay = "1up_mushroom.png"; break;
        case 13: overlay = "trampoline.png"; break;
        case 14: overlay = "coin_super_mushroom.png"; break;
        default: return; break;
    }

    if ((spr->getheight() == 20) && (spr->getwidth() == 20))
        painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), 20, 20, QPixmap(basePath + overlay));
    else
        painter->drawPixmap(spr->getx()+spr->getOffsetX()+20, spr->gety()+spr->getOffsetY(), 20, 20, QPixmap(basePath + overlay));
}


// Sprite 280: + Clock
ClockRenderer::ClockRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void ClockRenderer::render(QPainter *painter, QRect *)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) != 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "clock_50.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "clock_10.png"));
}

// Sprite 134: 3 Plat Rickshaw ruins
RuinsRickRenderer::RuinsRickRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "3Plat_Rickshaw_Ruins_Big.png");
    else img = new NormalImageRenderer(spr, basePath + "3Plat_Rickshaw_Ruins.png");
}

void RuinsRickRenderer::render(QPainter *painter, QRect *drawrect)
{
    img->render(painter, drawrect);
}

// Entrance Renderer
EntranceRenderer::EntranceRenderer(const Entrance *entrance)
{
    this->entr = entrance;

    this->rect = new RoundedRectRenderer(entrance, "", QColor(255,0,0,150));
}

void EntranceRenderer::render(QPainter *painter, QRect *drawrect)
{
    rect->render(painter, drawrect);
    QRect textRect(entr->getx()+2, entr->gety()+1, 16, 20);
    QRect imgRect(entr->getx(), entr->gety(), 20, 20);

    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/entrances/");

    switch (entr->getEntrType())
    {
    case 0: case 1:
        painter->drawText(textRect, "N", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "normal.png"));
        break;
    case 2:
        painter->drawPixmap(imgRect, QPixmap(basePath + "door_exit.png"));
        break;
    case 3:
        painter->drawPixmap(imgRect, QPixmap(basePath + "pipe_up.png"));
        break;
    case 4:
        painter->drawPixmap(imgRect, QPixmap(basePath + "pipe_down.png"));
        break;
    case 5:
        painter->drawPixmap(imgRect, QPixmap(basePath + "pipe_left.png"));
        break;
    case 6:
        painter->drawPixmap(imgRect, QPixmap(basePath + "pipe_right.png"));
        break;
    case 7:
        painter->drawText(textRect, "F", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "down.png"));
        break;
    case 8:
        painter->drawText(textRect, "G", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "down.png"));
        break;
    case 9:
        painter->drawText(textRect, "S", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "normal.png"));
        break;
    case 10:
        painter->drawText(textRect, "S", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "swimming.png"));
        break;
    case 20:
        painter->drawText(textRect, "J", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "up.png"));
        break;
    case 21:
        painter->drawText(textRect, "V", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "up.png"));
        break;
    case 23: case 25: case 26:
        painter->drawText(textRect, "B", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "normal.png"));
        break;
    case 24:
        painter->drawText(textRect, "J", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "left.png"));
        break;
    case 27:
        painter->drawPixmap(imgRect, QPixmap(basePath + "door_entrance.png"));
        break;
    default:painter->drawText(textRect, "?", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "unknown.png"));
        break;
    }

    painter->setFont(QFont("Arial", 7, QFont::Normal));
    painter->drawText(textRect, QString("%1").arg(entr->getid()), Qt::AlignLeft | Qt::AlignTop);
}


// Liquid Renderer

LiquidRenderer::LiquidRenderer(const Sprite *liquid, const Zone *zone)
{
    this->liquid = liquid;
    this->zone = zone;

    if (liquid->getid() == 12)
        filename = "lava";
    else if (liquid->getid() == 13)
        filename = "poison";
    else
        filename = "water";
}

void LiquidRenderer::render(QPainter *painter, QRect *drawrect)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/coinkiller_data/sprites/");

    QPixmap top = QPixmap(basePath + filename + "_top.png");
    QPixmap base = QPixmap(basePath + filename + ".png");

    int currY = liquid->gety() - 20;

    for (int x = zone->getx(); x < zone->getx() + zone->getwidth(); x += top.width())
    {
        QRect rect = QRect(x, currY, qMin(zone->getx() + zone->getwidth() - x, top.width()), qMin(zone->gety() + zone->getheight() - currY, top.height()));

        if (!drawrect->intersects(rect))
            continue;

        painter->drawPixmap(rect, top, QRect(0, 0, rect.right()-rect.left(), rect.bottom()-rect.top()));
    }

    currY += top.height();

    for (currY; currY < zone->gety() + zone->getheight(); currY += base.height())
    {
        for (int x = zone->getx(); x < zone->getx() + zone->getwidth(); x += base.width())
        {
            QRect rect = QRect(x, currY, qMin(zone->getx() + zone->getwidth() - x, base.width()), qMin(zone->gety() + zone->getheight() - currY, base.height()));

            if (!drawrect->intersects(rect))
                continue;

            painter->drawPixmap(rect, base, QRect(0, 0, rect.right()-rect.left(), rect.bottom()-rect.top()));
        }
    }
}
