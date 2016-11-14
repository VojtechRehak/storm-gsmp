#ifndef STORM_STORAGE_EXPRESSIONS_BINARYRELATIONEXPRESSION_H_
#define STORM_STORAGE_EXPRESSIONS_BINARYRELATIONEXPRESSION_H_

#include "src/storage/expressions/BinaryExpression.h"
#include "src/utility/OsDetection.h"

namespace storm {
    namespace expressions {
        class BinaryRelationExpression : public BinaryExpression {
        public:
            /*!
             * An enum type specifying the different relations applicable.
             */
            enum class RelationType {Equal, NotEqual, Less, LessOrEqual, Greater, GreaterOrEqual};
            
            /*!
             * Creates a binary relation expression with the given return type, operands and relation type.
             *
             * @param manager The manager responsible for this expression.
             * @param type The return type of the expression.
             * @param firstOperand The first operand of the expression.
             * @param secondOperand The second operand of the expression.
             * @param relationType The operator of the expression.
             */
            BinaryRelationExpression(ExpressionManager const& manager, Type const& type, std::shared_ptr<BaseExpression const> const& firstOperand, std::shared_ptr<BaseExpression const> const& secondOperand, RelationType relationType);
            
            // Instantiate constructors and assignments with their default implementations.
            BinaryRelationExpression(BinaryRelationExpression const& other) = default;
            BinaryRelationExpression& operator=(BinaryRelationExpression const& other) = default;
#ifndef WINDOWS
            BinaryRelationExpression(BinaryRelationExpression&&) = default;
            BinaryRelationExpression& operator=(BinaryRelationExpression&&) = default;
#endif
            virtual ~BinaryRelationExpression() = default;
            
            // Override base class methods.
            virtual storm::expressions::OperatorType getOperator() const override;
            virtual bool evaluateAsBool(Valuation const* valuation = nullptr) const override;
            virtual std::shared_ptr<BaseExpression const> simplify() const override;
            virtual boost::any accept(ExpressionVisitor& visitor, boost::any const& data) const override;

            /*!
             * Retrieves the relation associated with the expression.
             *
             * @return The relation associated with the expression.
             */
            RelationType getRelationType() const;
            
        protected:
            // Override base class method.
            virtual void printToStream(std::ostream& stream) const override;

        private:
            // The relation type of the expression.
            RelationType relationType;
        };
    }
}

#endif /* STORM_STORAGE_EXPRESSIONS_BINARYRELATIONEXPRESSION_H_ */