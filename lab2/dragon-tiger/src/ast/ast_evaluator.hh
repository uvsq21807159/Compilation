#ifndef AST_EVALUATOR_HH
#define AST_EVALUATOR_HH

#include <ostream>

#include "nodes.hh"


namespace ast {

class ASTEvaluator : public ConstASTIntVisitor {
  std::ostream *ostream;
  bool verbose;
  unsigned indent_level = 0;
  void inc() { indent_level++; }
  void inl() {
    inc();
    nl();
  };
  void dec() { indent_level--; }
  void dnl() {
    dec();
    nl();
  };
public:
	ASTEvaluator(std::ostream *_ostream, bool _verbose)
      : ostream(_ostream), verbose(_verbose) {}
  void nl() {
    *ostream << std::endl;
    for (unsigned i = 0; i < indent_level; i++)
      *ostream << "  ";
  };
  virtual int visit(const IntegerLiteral &);
  virtual int visit(const StringLiteral &);
  virtual int visit(const BinaryOperator &);
  virtual int visit(const Sequence &);
  virtual int visit(const Let &);
  virtual int visit(const Identifier &);
  virtual int visit(const IfThenElse &);
  virtual int visit(const VarDecl &);
  virtual int visit(const FunDecl &);
  virtual int visit(const FunCall &);
  virtual int visit(const WhileLoop &);
  virtual int visit(const ForLoop &);
  virtual int visit(const Break &);
  virtual int visit(const Assign &);
	
};

}



#endif
