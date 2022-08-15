#ifndef UNDO_H
#define UNDO_H
#include "product.h"
#include "repository.h"

class UndoAction {
public:
  virtual void do_undo() = 0;

  virtual ~UndoAction() = default;

  UndoAction() = default;

  UndoAction(const UndoAction &x) = delete;

  UndoAction &operator=(const UndoAction &) = delete;

  UndoAction(UndoAction &&) = default;

  UndoAction &operator=(UndoAction &&) = delete;
};

class UndoAdd : public UndoAction {
private:
  product to_add;
  repository &repo;

public:
  UndoAdd(product to_add, repository &repo) : to_add{to_add}, repo{repo} {}

  void do_undo() override { repo.remove(to_add); }
};

class UndoRemove : public UndoAction {
private:
  product to_remove;
  repository &repo;

public:
  UndoRemove(product to_remove, repository &repo)
      : to_remove{to_remove}, repo{repo} {}

  void do_undo() override { repo.add(to_remove); }
};

class UndoModify : public UndoAction {
private:
  product to_modify;
  repository &repo;

public:
  UndoModify(product to_modify, repository &repo)
      : to_modify{to_modify}, repo{repo} {}

  void do_undo() override { repo.modify(to_modify); }
};

#endif // UNDO_H
