// expression trees
// leaf nodes are operands and all others are operators

// inorder gives infix of expression
// postorder gives postfix of expression

// postorder to expression tree requires a STACK

// if operand, push pointer to that inside
// if operator, pop the last 2 operands and assign them left and right
// push pointer to operator inside stack (the one with left and right)