#ifndef EDITORCOMMAND_INSERTZONEBOUNDING_H
#define EDITORCOMMAND_INSERTZONEBOUNDING_H

#include <QUndoCommand>

#include "level.h"

namespace EditorCommand {

class InsertZoneBounding : public QUndoCommand
{
public:
    InsertZoneBounding(Level *level, ZoneBounding *bounding);
    ~InsertZoneBounding();

    void undo() override;
    void redo() override;

private:
    Level *level;
    ZoneBounding *bounding;
    bool deletable = false;
};

} // namespace EditorCommand

#endif // EDITORCOMMAND_INSERTZONEBOUNDING_H