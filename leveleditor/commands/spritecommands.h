#ifndef COMMANDS_SPRITECMD_H
#define COMMANDS_SPRITECMD_H

#include <QUndoCommand>

#include "commandids.h"
#include "objects.h"

namespace Commands::SpriteCmd {

class SetId : public QUndoCommand
{
public:
    SetId(Sprite *spr, quint16 id);

    void undo() override;
    void redo() override;
    int id() const override { return CommandID::SpriteCmd_SetId; };
    bool mergeWith(const QUndoCommand *cmd) override;

private:
    void updateText();

    Sprite *spr;
    quint16 newId;
    const quint16 oldId;
};


class SetLayer : public QUndoCommand
{
public:
    SetLayer(Sprite *spr, quint8 layer);

    void undo() override;
    void redo() override;
    int id() const override { return CommandID::SpriteCmd_SetLayer; };
    bool mergeWith(const QUndoCommand *cmd) override;

private:
    void updateText();

    Sprite *const spr;
    quint8 newLayer;
    const quint8 oldLayer;
};


class SetBits : public QUndoCommand
{
public:
    SetBits(Sprite *spr, qint32 data, qint32 start, qint32 end);

    void undo() override;
    void redo() override;
    int id() const override { return CommandID::SpriteCmd_SetBits; };
    bool mergeWith(const QUndoCommand *cmd) override;

private:
    void updateText();

    Sprite *const spr;
    qint32 newData;
    const qint32 oldData;
    const qint32 start;
    const qint32 end;
};


class SetByte : public QUndoCommand
{
public:
    SetByte(Sprite *spr, qint32 byteIndex, quint8 value);

    void undo() override;
    void redo() override;
    int id() const override { return CommandID::SpriteCmd_SetByte; };
    bool mergeWith(const QUndoCommand *cmd) override;

private:
    void updateText();

    Sprite *const spr;
    const qint32 byteIndex;
    quint8 newValue;
    const quint8 oldValue;
};


class SetNybbleData : public QUndoCommand
{
public:
    SetNybbleData(Sprite *spr, qint32 data, qint32 start, qint32 end);

    void undo() override;
    void redo() override;
    int id() const override { return CommandID::SpriteCmd_SetNybbleData; };
    bool mergeWith(const QUndoCommand *cmd) override;

private:
    void updateText();

    Sprite *const spr;
    qint32 newData;
    const qint32 oldData;
    const qint32 start;
    const qint32 end;
};

} // namespace Commands::SpriteCmd

#endif // COMMANDS_SPRITECMD_H
