#ifndef STORM_STORAGE_EXPRESSIONS_TOEXPRTKSTRINGVISITOR_H_
#define STORM_STORAGE_EXPRESSIONS_TOEXPRTKSTRINGVISITOR_H_

#include <sstream>

#include "src/storage/expressions/Expression.h"
#include "src/storage/expressions/Expressions.h"
#include "src/storage/expressions/ExpressionVisitor.h"

namespace storm {
    namespace expressions {
        class ToExprtkStringVisitor : public ExpressionVisitor {
        public:
            ToExprtkStringVisitor() = default;

            std::string toString(Expression const& expression);
            std::string toString(BaseExpression const* expression);
            
            virtual boost::any visit(IfThenElseExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(BinaryBooleanFunctionExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(BinaryNumericalFunctionExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(BinaryRelationExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(VariableExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(UnaryBooleanFunctionExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(UnaryNumericalFunctionExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(BooleanLiteralExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(IntegerLiteralExpression const& expression, boost::any const& data) override;
            virtual boost::any visit(RationalLiteralExpression const& expression, boost::any const& data) override;
            
        private:
            std::stringstream stream;
        };
    }
}


#endif /* STORM_STORAGE_EXPRESSIONS_TOEXPRTKSTRINGVISITOR_H_ */