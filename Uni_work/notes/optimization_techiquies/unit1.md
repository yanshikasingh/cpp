# OPTIMIZATION TECHNIQUES — UNIT I
## Complete Exam Notes, Question Bank Practice, Tutorial Problems and Answer Key

**Course:** B.Tech. CSE — Optimization Techniques  
**Unit I:** Introduction to Optimization and Engineering Applications  
**Exam-focused reference:** IILM University Unit 1 Question Bank and Tutorial Sheet

> **How to use these notes:** Revise Sections 1–8 first. Then attempt the mixed practice set in Section 9 without looking at the answers. All worked solutions and answer keys are collected at the very end in Section 10.  
> **Equation format:** Equations use LaTeX. In a Markdown editor that supports MathJax/LaTeX, they should render as mathematical notation. If your editor does not render math, the source equations are still valid Markdown text.

---

# 1. INTRODUCTION TO OPTIMIZATION AND ENGINEERING

## 1.1 Meaning of optimization

**Optimization** is the mathematical process of finding the best feasible solution to a problem by maximizing or minimizing a specified objective while satisfying the given constraints.

- **Maximization:** finding the largest possible value, such as maximum profit, output, efficiency, or accuracy.
- **Minimization:** finding the smallest possible value, such as minimum cost, time, distance, energy consumption, or waste.

### Examples
1. A factory chooses how many units of two products to manufacture to maximize profit.
2. A transport company selects routes to minimize travel distance or fuel cost.
3. A power station decides how much electricity to generate from different sources to minimize cost while meeting demand.
4. A diet is selected to minimize cost while meeting nutrition requirements.
5. An engineer selects dimensions to minimize material use while maintaining strength and safety.

### Why optimization is important
- Resources such as time, money, labour, energy, and raw materials are limited.
- It provides a systematic and quantitative basis for decisions.
- It helps compare alternatives objectively.
- It can improve efficiency, productivity, quality, and sustainability.
- It supports engineering design, planning, scheduling, logistics, and control.

## 1.2 Basic components of an optimization problem

Every standard optimization model contains the following components.

### 1. Decision variables
Unknown quantities whose values must be chosen.

Example: $x_1$ = number of chairs and $x_2$ = number of tables.

### 2. Objective function
The mathematical expression to be maximized or minimized.

Example: if each chair earns ₹500 and each table earns ₹800,

$$
\text{Maximize } Z = 500x_1 + 800x_2
$$

### 3. Constraints
Equations or inequalities representing limitations, requirements, or rules.

Example: if each chair uses 2 carpentry hours, each table uses 4 hours, and only 100 hours are available,

$$
2x_1 + 4x_2 \leq 100
$$

### 4. Parameters
Known values supplied by the problem, such as profit per unit, resource availability, processing time, or demand.

### 5. Feasible solution
A choice of decision-variable values that satisfies **every** constraint, including sign and integer restrictions.

### 6. Feasible region
The set of all feasible solutions. In a two-variable graphical problem, it is the common region satisfying all constraints.

### 7. Optimal solution
A feasible solution that gives the best objective-function value among all feasible solutions.

### 8. Non-negativity or domain restrictions
In production problems, negative quantities are usually impossible:

$$
x_1 \geq 0,\qquad x_2 \geq 0
$$

If only whole units can be produced, variables may additionally be restricted to integers.

## 1.3 General mathematical statement

A general optimization problem can be written as

$$
\begin{aligned}
&\text{Maximize or minimize} && f(\mathbf{x})\\
&\text{subject to} && g_i(\mathbf{x}) \leq 0,\quad i=1,\ldots,m,\\
&&& h_j(\mathbf{x}) = 0,\quad j=1,\ldots,p,\\
&&& \mathbf{x}\in S.
\end{aligned}
$$

Here:
- $\mathbf{x}=(x_1,x_2,\ldots,x_n)$ is the vector of decision variables.
- $f(\mathbf{x})$ is the objective function.
- $g_i$ and $h_j$ represent inequality and equality constraints.
- $S$ describes domain restrictions, such as non-negativity, integer, or binary conditions.

A common linear programming form is

$$
\begin{aligned}
&\text{Maximize/minimize } Z = \sum_{j=1}^{n} c_jx_j\\
&\text{subject to } \sum_{j=1}^{n} a_{ij}x_j \leq b_i,\quad i=1,\ldots,m,\\
&x_j\geq 0,\quad j=1,\ldots,n.
\end{aligned}
$$

The inequality direction can be $\leq$, $\geq$, or $=$, depending on the meaning of the condition.

---

# 2. APPLICATIONS OF OPTIMIZATION

## 2.1 Engineering applications

| Area | Objective | Typical constraints |
|---|---|---|
| Production planning | Maximize profit or output | Machine hours, labour, materials, demand |
| Power generation | Minimize generation cost | Electricity demand, generator capacities, emissions |
| Transportation | Minimize shipping cost or distance | Supply, demand, vehicle capacity |
| Chemical engineering | Maximize yield/profit or minimize cost | Reactor time, raw materials, safety limits |
| Structural engineering | Minimize weight or cost | Strength, stability, displacement, safety |
| Electronics manufacturing | Maximize profit | Machine time, inspection time, components |
| Water blending | Minimize treatment/blending cost | Required volume and impurity limits |
| Solar energy | Maximize energy or profit | Panel capacity, land, machine hours, labour |
| Computer networks | Minimize delay or energy | Bandwidth, capacity, reliability |
| AI/ML | Minimize prediction loss | Model complexity, training time, data limits |

## 2.2 Business and management applications
- **Finance:** portfolio allocation and risk management.
- **Marketing:** select advertising channels to maximize reach within a budget.
- **Human resources:** allocate staff and shifts.
- **Inventory:** determine order quantities and reorder policies.
- **Supply chain:** choose suppliers, warehouses, and delivery schedules.
- **Project management:** allocate workers and resources to reduce completion time or cost.

## 2.3 Daily-life applications
- Finding the shortest route.
- Planning a low-cost diet that satisfies nutritional requirements.
- Allocating study time across subjects.
- Selecting a low-cost combination of travel options.
- Reducing household energy consumption.

## 2.4 Benefits and limitations

### Benefits
1. Makes decisions systematic and measurable.
2. Uses scarce resources efficiently.
3. Identifies trade-offs between competing objectives.
4. Helps evaluate different scenarios.
5. Supports planning and scheduling.
6. Can reduce cost, time, waste, and environmental impact.

### Limitations
1. The result depends on the quality and accuracy of input data.
2. Real systems may contain uncertain or changing conditions.
3. Some models simplify reality and may omit important factors.
4. Nonlinear or large problems may be computationally difficult.
5. A mathematically optimal solution may not be practical, ethical, or acceptable to stakeholders.
6. Multiple conflicting objectives may require trade-offs rather than one perfect solution.

---

# 3. STATEMENT OF AN OPTIMIZATION PROBLEM

A well-stated optimization problem specifies:
1. **What must be decided:** decision variables.
2. **What is to be achieved:** objective function.
3. **What rules must be obeyed:** constraints.
4. **What values are allowed:** domain and sign restrictions.
5. **What data are known:** parameters.

## 3.1 Objective function examples

### Profit maximization
If product A earns ₹40 per unit and product B earns ₹30 per unit:

$$
\text{Maximize } Z=40x_1+30x_2
$$

### Cost minimization
If two resources cost ₹5 and ₹7 per unit:

$$
\text{Minimize } C=5x_1+7x_2
$$

### Time minimization
If a plan has time components $t_1,t_2$, a simplified objective might be

$$
\text{Minimize } T=t_1+t_2
$$

The exact objective must reflect the wording and data of the problem.

## 3.2 Translate common phrases into constraints

| Wording in the question | Mathematical meaning |
|---|---|
| At most / no more than / maximum | $\leq$ |
| At least / minimum of / not less than | $\geq$ |
| Exactly / must equal | $=$ |
| Cannot exceed | $\leq$ |
| Demand is limited to 40 units | $x\leq 40$ |
| At least 100 units must be supplied | $x+y\geq 100$ |
| Available resource is 80 hours | Resource use $\leq 80$ |
| Must use all available resource | Resource use $=$ availability |
| Quantity cannot be negative | $x\geq 0$ |
| Whole number of vehicles | $x\in\mathbb{Z}_{\geq0}$ |
| Yes/no or selected/not selected | $x\in\{0,1\}$ |

**Exam tip:** “At most” and “at least” are frequently tested. Read these words carefully before writing the inequality.

---

# 4. OPTIMIZATION PROBLEM FORMULATION

## 4.1 Step-by-step method

Use this structure for almost every formulation question.

**Step 1 — Define the decision variables.**  
Write what each variable represents, with units if useful.

**Step 2 — Write the objective function.**  
Use the profit, cost, distance, time, or other quantity given in the question. Use Maximize or Minimize exactly as required.

**Step 3 — Write resource constraints.**  
For every resource, multiply the amount used per unit by the decision variable and compare total use with availability.

**Step 4 — Write demand, quality, capacity, or policy constraints.**  
Do not forget maximum production limits, minimum output requirements, emission limits, or blending conditions.

**Step 5 — Write sign and domain restrictions.**  
Usually $x_i\geq0$; if specified, use integer or binary restrictions.

**Step 6 — State the complete model.**  
Present the variables, objective, all constraints, and domains together.

## 4.2 Worked formulation: furniture company

A chair earns ₹500 and a table earns ₹800. A chair needs 2 carpentry hours and 1 polishing hour. A table needs 4 carpentry hours and 2 polishing hours. There are 100 carpentry hours and 50 polishing hours.

Let:
- $x$ = chairs produced per week.
- $y$ = tables produced per week.

Profit:

$$
\text{Maximize } Z=500x+800y
$$

Carpentry constraint:

$$
2x+4y\leq100
$$

Polishing constraint:

$$
x+2y\leq50
$$

Non-negativity:

$$
x\geq0,\qquad y\geq0
$$

This is the required Linear Programming Problem (LPP). Notice that the polishing constraint is a multiple of the carpentry constraint in this example; it is still correct to include both.

## 4.3 Worked formulation: diet problem

Food X provides 4 protein units and 2 vitamin units per serving and costs ₹30. Food Y provides 2 protein units and 5 vitamin units and costs ₹20. At least 40 protein units and 30 vitamin units are required.

Let $x$ and $y$ be servings of foods X and Y.

$$
\text{Minimize } C=30x+20y
$$

Protein requirement:

$$
4x+2y\geq40
$$

Vitamin requirement:

$$
2x+5y\geq30
$$

$$
x\geq0,\qquad y\geq0
$$

## 4.4 Linear Programming Problem (LPP)

An LPP is an optimization problem in which:
- The objective function is linear.
- Every constraint is linear.
- Decision variables are normally continuous and non-negative unless stated otherwise.

General form:

$$
\text{Maximize/minimize } Z=c_1x_1+c_2x_2+\cdots+c_nx_n
$$

subject to linear constraints such as

$$
a_{i1}x_1+a_{i2}x_2+\cdots+a_{in}x_n\leq b_i
$$

and

$$
x_j\geq0.
$$

### Assumptions of Linear Programming
1. **Proportionality:** contribution and resource use per unit remain constant.
2. **Additivity:** total contribution and resource use equal the sum of individual contributions.
3. **Divisibility:** variables may take fractional values in the basic LP model.
4. **Certainty:** coefficients are known and fixed.
5. **Non-negativity:** decision variables are generally non-negative.

### Advantages of LPP
- Clear mathematical model.
- Efficient algorithms for many large problems.
- Helps allocate limited resources.
- Identifies feasible and optimal plans.
- Useful for sensitivity and scenario analysis.

### Limitations of LPP
- Linear relationships may not represent real systems accurately.
- Basic LP permits fractional quantities.
- Assumes known coefficients.
- A single objective may not represent all business or social goals.
- Human, environmental, and qualitative factors may be difficult to quantify.

## 4.5 Feasible region and corner points

For a two-variable LPP:
1. Convert each inequality into an equality to draw its boundary line.
2. Determine the side satisfying the inequality.
3. Include $x\geq0$ and $y\geq0$.
4. The common intersection is the feasible region.
5. In a standard LP with a nonempty bounded feasible region, an optimum (if one exists) occurs at at least one corner point.
6. Evaluate the objective at the feasible corner points to identify the optimum.

**Important cases:**
- **Feasible and bounded:** at least one optimum exists.
- **Infeasible:** no point satisfies all constraints.
- **Unbounded feasible region:** objective may be unbounded, although an optimum can still exist depending on the objective direction.
- **Multiple optimal solutions:** the objective has the same best value at more than one feasible point, often along an edge.
- **Redundant constraint:** a constraint that does not change the feasible region.
- **Binding constraint:** holds as equality at the solution.
- **Non-binding constraint:** has unused slack at the solution.

---

# 5. CLASSIFICATION OF OPTIMIZATION PROBLEMS

Optimization problems can be classified in several ways. A problem can belong to more than one category at the same time.

## 5.1 Constrained vs unconstrained

### Unconstrained optimization
There are no explicit constraints other than the domain of the variables.

Example:

$$
\text{Minimize } f(x,y)=x^2+y^2
$$

### Constrained optimization
The objective must be optimized while satisfying restrictions.

Example:

$$
\text{Maximize } Z=3x+2y
$$

subject to

$$
x+y\leq10,\qquad x\geq0,\quad y\geq0.
$$

## 5.2 Linear vs nonlinear

### Linear optimization
Both the objective and all constraints are linear.

$$
\text{Maximize } Z=5x+3y
$$

subject to

$$
2x+y\leq8,\qquad x+2y\leq10.
$$

### Nonlinear optimization
The objective or at least one constraint is nonlinear.

$$
\text{Minimize } f(x,y)=x^2+y^2
$$

subject to

$$
xy\geq1.
$$

## 5.3 Continuous vs integer vs binary

- **Continuous optimization:** variables may take real values, such as $x=2.5$.
- **Integer optimization:** one or more variables must be integers, such as number of trucks.
- **Binary or 0–1 optimization:** variables can only be 0 or 1.

$$
x_i\in\{0,1\}
$$

Binary variables often represent yes/no decisions: build/not build, select/not select, or activate/not activate.

## 5.4 Deterministic vs stochastic

- **Deterministic:** all model coefficients are treated as known.
- **Stochastic:** uncertainty is explicitly represented using random variables or probability distributions.

## 5.5 Single-objective vs multi-objective

- **Single-objective:** one objective, such as minimizing cost.
- **Multi-objective:** several objectives, such as minimizing cost and emissions while maximizing reliability. Objectives may conflict, so a trade-off or Pareto-optimal solution may be needed.

## 5.6 Static vs dynamic

- **Static:** decisions are made for one fixed period or state.
- **Dynamic:** decisions and system states evolve over time.

## 5.7 Convex vs non-convex

- **Convex optimization:** the feasible region is convex and the objective has the appropriate convexity for the problem. For minimization of a convex function over a convex feasible set, any local minimum is also a global minimum.
- **Non-convex optimization:** the problem may contain multiple local optima, making global optimization harder.

## 5.8 Summary table

| Classification | Type 1 | Type 2 |
|---|---|---|
| Constraints | Unconstrained | Constrained |
| Function form | Linear | Nonlinear |
| Variable domain | Continuous | Integer / binary |
| Data | Deterministic | Stochastic |
| Objectives | Single-objective | Multi-objective |
| Time | Static | Dynamic |
| Geometry | Convex | Non-convex |

---

# 6. GLOBAL AND LOCAL OPTIMUM

## 6.1 Local minimum and local maximum

A point $x^*$ is a **local minimum** if its objective value is no greater than the values at all sufficiently nearby feasible points.

$$
f(x^*)\leq f(x)
$$

for all feasible $x$ in some neighbourhood of $x^*$.

A point $x^*$ is a **local maximum** if

$$
f(x^*)\geq f(x)
$$

for all feasible $x$ in some neighbourhood of $x^*$.

## 6.2 Global minimum and global maximum

A point $x^*$ is a **global minimum** if

$$
f(x^*)\leq f(x)
$$

for every feasible $x$ in the entire feasible domain.

A point $x^*$ is a **global maximum** if

$$
f(x^*)\geq f(x)
$$

for every feasible $x$ in the entire feasible domain.

## 6.3 Difference between local and global optimum

| Local optimum | Global optimum |
|---|---|
| Best within a neighbourhood | Best over the entire feasible domain |
| Other distant points may be better | No feasible point has a better objective value |
| Common in non-convex problems | May be harder to prove in non-convex problems |
| A global optimum can also be local | A local optimum need not be global |

**Memory line:** Local = nearby; global = everywhere in the feasible domain.

## 6.4 Examples

### Example 1: upward-opening parabola

$$
f(x)=x^2
$$

$$
f'(x)=2x=0\implies x=0
$$

$$
f''(x)=2>0
$$

Thus $x=0$ is a local minimum. Since $x^2\geq0$ for every real $x$, it is also a global minimum, with value $0$.

### Example 2: downward-opening parabola

$$
f(x)=-x^2
$$

$$
f'(x)=-2x=0\implies x=0,\qquad f''(x)=-2<0
$$

Thus $x=0$ is both a local and global maximum, with value $0$.

### Example 3: local optimum need not be global

A non-convex function may have several peaks or valleys. One valley may be lower than nearby points but higher than another valley elsewhere. The first is a local minimum but not a global minimum.

## 6.5 Endpoints matter

For a function on a **closed interval** $[a,b]$, the global minimum and maximum may occur at:
- an interior critical point,
- the left endpoint $a$,
- the right endpoint $b$.

Therefore, always compare objective values at all critical points in the interval and at both endpoints.

---

# 7. OPTIMALITY CRITERIA AND REVIEW OF CALCULUS

## 7.1 Derivatives and critical points

For a differentiable single-variable function $f(x)$, an interior local optimum must satisfy the first-order necessary condition

$$
f'(x^*)=0.
$$

A critical point can also occur where $f'(x)$ does not exist. **Not every critical point is an optimum.** It may be a minimum, maximum, or neither.

## 7.2 First derivative test

Find $f'(x)$, solve $f'(x)=0$, and examine the sign of the derivative on either side of each critical point.

- $f'$ changes from negative to positive: local minimum.
- $f'$ changes from positive to negative: local maximum.
- $f'$ does not change sign: generally neither a local minimum nor maximum.

## 7.3 Second derivative test

For a twice-differentiable function, first find a critical point $x^*$ satisfying $f'(x^*)=0$. Then evaluate $f''(x^*)$.

| Condition | Classification |
|---|---|
| $f''(x^*)>0$ | Strict local minimum |
| $f''(x^*)<0$ | Strict local maximum |
| $f''(x^*)=0$ | Test is inconclusive |

When $f''(x^*)=0$, use the first derivative test, higher derivatives, or another suitable method.

### Example

$$
f(x)=x^2-4x+5
$$

First derivative:

$$
f'(x)=2x-4
$$

Critical point:

$$
2x-4=0\implies x=2
$$

Second derivative:

$$
f''(x)=2>0
$$

Therefore, $x=2$ is a local minimum. Its value is

$$
f(2)=2^2-4(2)+5=1.
$$

Because the parabola opens upward and $f(x)=(x-2)^2+1\geq1$ for every real $x$, this is also the global minimum.

## 7.4 Higher-order derivative idea

If $f'(x^*)=0$, and the first nonzero derivative after $f'$ is $f^{(n)}(x^*)$:
- if $n$ is even and the derivative is positive, the point is a local minimum;
- if $n$ is even and the derivative is negative, the point is a local maximum;
- if $n$ is odd, the point is generally not a local extremum.

This is a useful additional test, but the first and second derivative tests are the main exam essentials.

## 7.5 Multivariable first-order condition

For $f(x,y)$, the gradient is

$$
\nabla f(x,y)=\left(\frac{\partial f}{\partial x},\frac{\partial f}{\partial y}\right).
$$

An interior differentiable optimum must satisfy

$$
\frac{\partial f}{\partial x}=0,\qquad
\frac{\partial f}{\partial y}=0.
$$

For $n$ variables, set every first partial derivative to zero.

## 7.6 Multivariable second-order condition (basic idea)

The Hessian matrix contains second partial derivatives. For a twice-differentiable function:
- positive definite Hessian at a stationary point implies a strict local minimum;
- negative definite Hessian implies a strict local maximum;
- an indefinite Hessian indicates a saddle point;
- a semidefinite or singular Hessian may require further testing.

For a function $f(x,y)$, the Hessian is

$$
H=
\begin{bmatrix}
f_{xx} & f_{xy}\\
f_{yx} & f_{yy}
\end{bmatrix}.
$$

For a two-variable stationary point, define

$$
D=f_{xx}f_{yy}-(f_{xy})^2.
$$

- If $D>0$ and $f_{xx}>0$: local minimum.
- If $D>0$ and $f_{xx}<0$: local maximum.
- If $D<0$: saddle point.
- If $D=0$: test is inconclusive.

## 7.7 Constrained optimality: introductory view

For constrained problems, an unconstrained derivative test alone may not be sufficient. An optimum can occur:
- at an interior stationary point,
- on a constraint boundary,
- at the intersection of boundaries,
- at an endpoint or corner.

For a two-variable LPP, the graphical corner-point method is often suitable. More advanced constrained nonlinear problems may use Lagrange multipliers or Karush–Kuhn–Tucker (KKT) conditions.

### Lagrange multiplier method (basic equality-constrained case)

To optimize $f(x,y)$ subject to $g(x,y)=0$, define

$$
\mathcal{L}(x,y,\lambda)=f(x,y)+\lambda g(x,y).
$$

Solve

$$
\frac{\partial\mathcal{L}}{\partial x}=0,\qquad
\frac{\partial\mathcal{L}}{\partial y}=0,\qquad
\frac{\partial\mathcal{L}}{\partial\lambda}=0.
$$

This is introductory context; focus first on derivative tests and LPP formulation unless your instructor has emphasized Lagrange multipliers.

## 7.8 Common calculus patterns

### Quadratic function

$$
f(x)=ax^2+bx+c,\qquad a\neq0
$$

Critical point:

$$
f'(x)=2ax+b=0\implies x^*=-\frac{b}{2a}.
$$

- $a>0$: the parabola opens upward; the vertex is a global minimum.
- $a<0$: the parabola opens downward; the vertex is a global maximum.

### Completing the square

For example,

$$
x^2-4x+5=(x-2)^2+1.
$$

Since $(x-2)^2\geq0$, the global minimum is $1$ at $x=2$.

### Cubic function

For a cubic, calculate $f'(x)$, solve the quadratic equation $f'(x)=0$, and classify the critical points using $f''(x)$ or the first derivative test.

### Closed interval method
To find absolute/global extrema of a continuous function on $[a,b]$:
1. Find critical points inside $(a,b)$.
2. Evaluate $f$ at those points.
3. Evaluate $f(a)$ and $f(b)$.
4. Compare all values.

---

# 8. APPLICATION OF ARTIFICIAL INTELLIGENCE IN OPTIMIZATION

## 8.1 What is AI-based optimization?

AI-based optimization uses artificial intelligence, machine learning, or nature-inspired search methods to explore solution spaces, learn patterns, predict outcomes, or identify good solutions to complex optimization problems.

AI methods can be particularly useful when:
- the search space is very large;
- the objective function is difficult to differentiate;
- the system is nonlinear or non-convex;
- evaluations are expensive;
- data can help predict outcomes;
- exact optimization is impractical.

## 8.2 Important AI and nature-inspired methods

### 1. Genetic Algorithm (GA)
Inspired by biological evolution.

Basic steps:
1. Create an initial population of candidate solutions.
2. Evaluate each candidate using a fitness function.
3. Select promising candidates.
4. Apply crossover to combine candidates.
5. Apply mutation to introduce variation.
6. Repeat until a stopping condition is reached.

**Applications:** scheduling, design optimization, feature selection, routing, and parameter tuning.

### 2. Particle Swarm Optimization (PSO)
Inspired by the collective movement of bird flocks or fish schools.

- Each particle represents a candidate solution.
- It tracks its own best known position.
- It also uses the best position found by the swarm.
- Positions and velocities are updated iteratively.

**Applications:** engineering design, parameter tuning, power-system optimization, and continuous optimization.

### 3. Neural networks and machine learning
A trained model predicts outcomes or approximates an objective. An optimizer can then search for inputs that improve the predicted outcome.

**Applications:** process control, energy demand, predictive maintenance, material design, and surrogate modelling.

**Important distinction:** a neural network is commonly a predictive model; it can support optimization, but training a network and optimizing a real-world decision are not identical tasks.

### 4. Reinforcement learning (RL)
An agent learns a policy by interacting with an environment and receiving rewards or penalties.

**Applications:** adaptive control, robotics, traffic-signal control, and sequential decision-making.

### 5. Simulated Annealing (SA)
Inspired by the annealing process in metallurgy. It sometimes accepts a worse candidate early in the search to escape local optima, then gradually becomes less willing to do so.

### 6. Ant Colony Optimization (ACO)
Inspired by how ants use pheromone trails to find routes. It is often applied to routing and combinatorial problems.

## 8.3 Traditional vs AI-based optimization

| Traditional methods | AI-based / nature-inspired methods |
|---|---|
| Often use mathematical structure such as derivatives or linearity | Often search or learn from candidate solutions and data |
| Can provide exact optima under suitable assumptions | Often provide good or near-optimal solutions; global optimality may not be guaranteed |
| Examples: calculus, simplex method, gradient methods | Examples: GA, PSO, ACO, simulated annealing, learned surrogate models |
| May be efficient and interpretable for well-structured models | Can be useful for complex, nonlinear, discontinuous, or black-box problems |
| Performance depends on assumptions and model structure | Performance depends on representation, hyperparameters, data, and search budget |
| Some methods provide strong optimality guarantees | Many heuristic methods lack a proof of global optimality |

## 8.4 Advantages of AI in optimization
1. Can search large and complex spaces.
2. Can handle some nonlinear and non-differentiable objectives.
3. May avoid getting trapped in some local optima through exploration.
4. Can use data to estimate outcomes.
5. Can adapt to changing environments in suitable implementations.
6. Can find useful near-optimal solutions where exact methods are too expensive.

## 8.5 Limitations of AI in optimization
1. No guarantee of the global optimum for many heuristic methods.
2. Results may vary across runs.
3. Parameter tuning can be difficult.
4. Training or search may require significant time and computing resources.
5. Poor-quality or biased data can produce poor results.
6. Some models are hard to interpret.
7. Results must be checked for feasibility, safety, robustness, and real-world performance.

## 8.6 How AI improves optimization
AI may improve optimization by:
- learning an approximate objective from data;
- predicting demand, cost, failures, or energy use;
- proposing promising candidate solutions;
- tuning algorithm parameters;
- searching large spaces;
- supporting real-time decisions;
- combining predictions with traditional mathematical optimization.

**Exam-ready conclusion:** AI expands the range of problems that can be tackled and can find high-quality solutions for complex search spaces. However, AI results should be validated, and traditional optimization remains powerful when a problem has a clear mathematical structure and strong guarantees are needed.

---

# 9. MIXED EXAM PRACTICE — ATTEMPT BEFORE CHECKING THE ANSWERS

This section mixes questions based on the supplied Unit 1 Question Bank and Tutorial Sheet with additional practice questions covering the same syllabus. The answer key and full worked solutions appear in Section 10.

## Part A — MCQs (20)

**A1.** Optimization is the process of:
- A. Increasing the cost of a system
- B. Finding the best feasible solution
- C. Eliminating all constraints
- D. Reducing the number of variables

**A2.** The function to be maximized or minimized is called:
- A. Constraint function
- B. Objective function
- C. Decision variable
- D. Parameter

**A3.** Variables whose values must be determined are:
- A. Parameters
- B. Constraints
- C. Decision variables
- D. Constants

**A4.** A solution satisfying every constraint is called:
- A. Local solution
- B. Feasible solution
- C. Global solution
- D. Infeasible solution

**A5.** The set of all feasible solutions is the:
- A. Objective function
- B. Gradient
- C. Feasible region
- D. Parameter space only

**A6.** “At most 60 units” is represented by:
- A. $x\geq60$
- B. $x=60$
- C. $x\leq60$
- D. $x<0$

**A7.** Which is an unconstrained optimization problem?
- A. Minimize $x^2+y^2$
- B. Minimize $x+y$, subject to $x+y\leq10$
- C. Maximize profit subject to machine limits
- D. Minimize transport cost subject to demand

**A8.** A global optimum is best among:
- A. Nearby points only
- B. All feasible points
- C. Infeasible points only
- D. Random points only

**A9.** If $f'(x^*)=0$ and $f''(x^*)>0$, the second derivative test indicates:
- A. Strict local maximum
- B. Strict local minimum
- C. Always a saddle point
- D. No critical point

**A10.** If $f''(x^*)=0$, the second derivative test is:
- A. Always a minimum
- B. Always a maximum
- C. Inconclusive
- D. Proof of global optimality

**A11.** A Genetic Algorithm is inspired by:
- A. Natural evolution
- B. Newton’s law of cooling only
- C. Matrix inversion
- D. Linear regression only

**A12.** Particle Swarm Optimization is inspired by:
- A. Evolution through chromosomes only
- B. Collective movement of swarms
- C. Binary arithmetic
- D. The simplex tableau

**A13.** Which is a linear objective function?
- A. $x^2+y$
- B. $xy+1$
- C. $5x+3y$
- D. $\sin x+y$

**A14.** A binary decision variable can take:
- A. Any real value
- B. Any integer
- C. Only 0 or 1
- D. Only negative values

**A15.** In a standard production model, a resource availability constraint is commonly:
- A. Resource use $\geq$ availability
- B. Resource use $\leq$ availability
- C. Resource use must be negative
- D. Resource use has no relation to availability

**A16.** Which is an example of optimization?
- A. Finding the shortest route
- B. Printing a document
- C. Opening a folder
- D. Typing a paragraph

**A17.** A local minimum is the best point:
- A. Over the entire domain necessarily
- B. In a sufficiently small neighbourhood
- C. Among infeasible points
- D. Only at the origin

**A18.** Which method is associated with ant-inspired routing?
- A. Ant Colony Optimization
- B. Newton’s method
- C. Gaussian elimination
- D. Ordinary least squares

**A19.** One common limitation of heuristic AI optimization is:
- A. It can never search nonlinear spaces
- B. It always proves the global optimum
- C. It may not guarantee a global optimum
- D. It cannot represent candidate solutions

**A20.** The main purpose of formulation is to:
- A. Define variables, objective, and constraints
- B. Remove all constraints
- C. Draw any graph without a model
- D. Replace all quantities with constants

## Part B — Short-answer questions

**B1.** Explain optimization with two engineering examples.

**B2.** Differentiate between objective function and constraints.

**B3.** Define decision variables, feasible solution, feasible region, and optimal solution.

**B4.** Differentiate between local optimum and global optimum.

**B5.** State and explain the first and second derivative tests.

**B6.** Differentiate between linear and nonlinear optimization.

**B7.** Explain constrained and unconstrained optimization with one example each.

**B8.** State the assumptions, advantages, and limitations of Linear Programming.

**B9.** Explain the applications of AI in optimization.

**B10.** Compare traditional optimization methods with AI-based methods.

**B11.** Explain Genetic Algorithm steps.

**B12.** What are binding, non-binding, and redundant constraints?

**B13.** Explain infeasible, unbounded, and multiple-optimum cases.

**B14.** Why must endpoints be checked when finding global extrema on a closed interval?

**B15.** Explain how the words “at most,” “at least,” and “exactly” are translated into mathematical constraints.

## Part C — Formulation questions

**C1. Furniture:** A chair earns ₹500 and a table ₹800. Each chair needs 2 carpentry hours and 1 polishing hour; each table needs 4 carpentry hours and 2 polishing hours. Available hours are 100 carpentry and 50 polishing. Formulate an LPP to maximize profit.

**C2. Factory:** Product A earns ₹40 and uses 2 kg of material and 1 labour hour. Product B earns ₹30 and uses 1 kg of material and 2 labour hours. There are 100 kg of material and 80 labour hours. Formulate the LPP.

**C3. Diet:** Food X provides 4 protein and 2 vitamin units at ₹30 per serving. Food Y provides 2 protein and 5 vitamin units at ₹20. At least 40 protein and 30 vitamin units are required. Formulate a minimum-cost LPP.

**C4. Advertising:** A TV advertisement reaches 20,000 people and costs ₹50,000. A social-media campaign reaches 8,000 people and costs ₹15,000. Reach must be at least 200,000 people and spending must not exceed ₹6,00,000. Formulate a model. State whether it is a maximization or minimization problem as written.

**C5. Three products:** Products $P_1,P_2,P_3$ use machining hours $(2,3,1)$, assembly hours $(1,2,2)$, and finishing hours $(1,1,2)$. Available hours are 120, 100, and 80, respectively. Profits per unit are ₹50, ₹60, and ₹40. Formulate the LPP.

**C6. Two-product engineering model:** Products A and B earn ₹50 and ₹40. A uses 2 machine hours and 1 labour hour; B uses 1 machine hour and 2 labour hours. There are 100 machine hours and 80 labour hours. Formulate the LPP and describe how the feasible region is identified.

**C7. Transportation:** A small truck carries 5 tonnes and costs ₹3,000 per trip. A large truck carries 10 tonnes and costs ₹5,000 per trip. At least 100 tonnes must be transported. Formulate a minimum-cost model. If trips must be whole numbers, state the domain.

**C8. Three-variable challenge:** A manufacturer produces three products. Let profits be $50,60,40$. Their machining use is $2,3,1$, assembly use $1,2,2$, and finishing use $1,1,2$. Capacities are 120, 100, and 80. Write the complete model and all non-negativity restrictions.

## Part D — Calculus and classification problems

**D1.** Find and classify the critical point of $f(x)=x^2-4x+5$. Is it global?

**D2.** Find the global minimum of $f(x)=3x^2-12x+7$. Classify the optimum.

**D3.** Find global maximum and minimum of $f(x)=x^2-4x+1$ on $0\leq x\leq5$.

**D4.** For $f(x)=x^3-3x^2-9x+2$, find all critical points and classify them using the second derivative test.

**D5.** Find and classify the critical point(s) of $f(x)=x^3$. Explain why the second derivative test alone is inconclusive at the critical point.

**D6.** Classify the stationary point of $f(x,y)=x^2+y^2$ at $(0,0)$ using the Hessian.

**D7.** Classify the stationary point of $f(x,y)=x^2-y^2$ at $(0,0)$.

**D8.** A continuous function is defined on $[1,4]$. Its interior critical points are $x=2$ and $x=3$. Explain the method for finding its absolute maximum and minimum even if the function is not supplied.

## Part E — Tutorial-sheet engineering applications

For each problem, formulate the mathematical model and determine the optimal plan where the supplied data are sufficient. Assume non-negative continuous quantities unless whole trips/units are explicitly required.

**E1. Production planning:** Product A uses 2 machining hours and 1 assembly hour; B uses 1 machining hour and 2 assembly hours. There are 100 machining hours and 80 assembly hours. Profits are $40 and $30. Demand limits are $A\leq40$, $B\leq50$.

**E2. Power generation:** Coal costs $60/MWh and gas costs $80/MWh. At least 300 MWh is required. Coal capacity is 180 MWh and gas capacity 200 MWh. Emission index is $2C+G\leq500$. Minimize cost.

**E3. Chemical production:** Chemical A uses 3 reactor hours and 2 kg raw material; B uses 2 reactor hours and 4 kg. Capacities are 180 reactor hours and 200 kg. $A\leq40$. Profits are $50 and $70.

**E4. Transportation:** Plant 1 costs $8/tonne and supplies at most 70 tonnes; Plant 2 costs $6/tonne and supplies at most 80 tonnes. At least 120 tonnes must be delivered. Minimize cost.

**E5. Steel mill:** Bars use 4 furnace and 2 finishing hours per tonne; rods use 3 furnace and 1 finishing hour. Capacities are 240 furnace and 100 finishing hours. Rods are limited to 50 tonnes. Profits are $55/tonne for bars and $45/tonne for rods.

**E6. Electronics:** Model I uses 5 SMT and 2 inspection hours; Model II uses 4 SMT and 3 inspection hours. Capacities are 400 SMT and 180 inspection hours. Model I is limited to 60 units. Profits are $120 and $100.

**E7. Construction materials:** Concrete costs $90/batch and asphalt $110/batch. At least 150 batches are required. Strength requirement is $3C+2A\geq360$. Concrete is limited to 100 batches. Minimize cost.

**E8. Water blending:** Exactly 100 million litres are needed. Source I costs $5 per million litres and has 2% impurities. Source II costs $7 and has 8% impurities. Total impurities must be no more than 5 million litres. Minimize cost.

**E9. Solar panels:** Residential panels use 6 machine hours and 4 labour hours; commercial panels use 10 machine hours and 3 labour hours. Capacities are 600 machine hours and 300 labour hours. Commercial panels are limited to 30. Profits are $200 and $350.

**E10. Warehouse logistics:** A truck carries 20 tonnes and costs $500 per trip. A rail wagon carries 50 tonnes and costs $300 per trip. At least 500 tonnes must be transported. At most 20 truck trips and 10 rail trips are available. Minimize cost. Consider trips as whole numbers.

---

# 10. ANSWER KEY AND FULL WORKED SOLUTIONS

**Stop here if you still want to attempt the practice questions independently.** This final section contains the answers and worked methods.

## 10.1 Part A — MCQ answer key

| Question | Answer | Reason |
|---|---|---|
| A1 | B | Optimization finds the best feasible solution. |
| A2 | B | The objective function is what is maximized or minimized. |
| A3 | C | Decision variables are the unknown choices. |
| A4 | B | A feasible solution satisfies all constraints. |
| A5 | C | The feasible region contains all feasible solutions. |
| A6 | C | “At most” means less than or equal to. |
| A7 | A | No explicit constraints are stated. |
| A8 | B | Global means over the entire feasible domain. |
| A9 | B | Positive second derivative indicates a strict local minimum at a stationary point. |
| A10 | C | The second derivative test is inconclusive when it is zero. |
| A11 | A | Genetic Algorithms imitate natural evolution. |
| A12 | B | PSO is inspired by collective swarm movement. |
| A13 | C | $5x+3y$ is linear. |
| A14 | C | A binary variable is 0 or 1. |
| A15 | B | Resource use cannot exceed available capacity in the usual resource constraint. |
| A16 | A | A shortest-route problem is an optimization problem. |
| A17 | B | Local optimum is best within a neighbourhood. |
| A18 | A | Ant Colony Optimization is inspired by ant trails. |
| A19 | C | Heuristics may not prove global optimality. |
| A20 | A | Formulation defines variables, objective, and constraints. |

## 10.2 Part B — Model short answers

### B1. Explain optimization with two engineering examples.
Optimization is the process of finding the best feasible solution by maximizing or minimizing an objective function subject to constraints. In production planning, a factory maximizes profit while respecting machine and labour capacities. In power generation, a plant minimizes generation cost while meeting electricity demand and emission limits.

### B2. Objective function vs constraints
The objective function expresses the quantity to be optimized, such as $Z=40x+30y$. Constraints represent limitations or requirements, such as $2x+y\leq100$. The objective says what is desired; constraints specify what is allowed.

### B3. Define key terms
- **Decision variables:** unknown choices to be determined.
- **Feasible solution:** a choice satisfying every constraint.
- **Feasible region:** the set of all feasible solutions.
- **Optimal solution:** a feasible solution with the best objective value.

### B4. Local vs global optimum
A local optimum is best within a sufficiently small neighbourhood. A global optimum is best over the entire feasible domain. A global optimum is often also local, but a local optimum need not be global.

### B5. First and second derivative tests
At an interior differentiable optimum, a necessary condition is $f'(x^*)=0$. Under the second derivative test, if $f''(x^*)>0$, the point is a strict local minimum; if $f''(x^*)<0$, it is a strict local maximum; if $f''(x^*)=0$, the test is inconclusive.

### B6. Linear vs nonlinear optimization
In linear optimization, the objective and all constraints are linear, e.g. $Z=5x+3y$. In nonlinear optimization, the objective or at least one constraint is nonlinear, e.g. $f(x,y)=x^2+y^2$.

### B7. Constrained vs unconstrained
Unconstrained optimization has no explicit constraints, e.g. minimize $x^2+y^2$. Constrained optimization includes restrictions, e.g. maximize $3x+2y$ subject to $x+y\leq10$ and $x,y\geq0$.

### B8. LPP assumptions, advantages, limitations
**Assumptions:** proportionality, additivity, divisibility, certainty, and non-negativity.  
**Advantages:** systematic resource allocation, clear modelling, efficient solution methods, and objective comparison.  
**Limitations:** linearity and certainty may be unrealistic; fractional solutions may be impractical; qualitative factors and multiple objectives can be difficult to represent.

### B9. Applications of AI in optimization
AI can predict outcomes, search large solution spaces, tune parameters, and suggest high-quality solutions. Genetic Algorithms are used in scheduling and design, PSO in continuous parameter optimization, and reinforcement learning in sequential control. AI methods can be useful for nonlinear or black-box problems, but they may require considerable computation and may not guarantee a global optimum.

### B10. Traditional vs AI-based methods
Traditional methods such as calculus, gradient methods, and linear programming exploit mathematical structure and can provide guarantees under suitable assumptions. AI-based methods such as GA and PSO use population-based search or learned predictions and can tackle complex search spaces, but often provide near-optimal rather than guaranteed global solutions.

### B11. Genetic Algorithm steps
1. Generate an initial population.
2. Evaluate fitness.
3. Select candidate parents.
4. Apply crossover.
5. Apply mutation.
6. Form the next population.
7. Repeat until a stopping condition is met.
8. Return the best feasible candidate found.

### B12. Binding, non-binding, redundant constraints
A binding constraint is satisfied as equality at the solution. A non-binding constraint has slack. A redundant constraint does not change the feasible region because it is already implied by the other constraints.

### B13. Infeasible, unbounded, multiple optimum
- **Infeasible:** no solution satisfies all constraints.
- **Unbounded:** the objective can improve without limit within the feasible region.
- **Multiple optima:** more than one feasible point gives the same optimal objective value.

### B14. Why check endpoints?
On a closed interval, the absolute maximum or minimum can occur at an endpoint even if the derivative is nonzero there. Therefore, compare all interior critical-point values with both endpoint values.

### B15. Translate common wording
“At most” means $\leq$; “at least” means $\geq$; “exactly” means $=$. For example, at most 40 units gives $x\leq40$, at least 100 units gives $x\geq100$, and exactly 100 units gives $x=100$.

## 10.3 Part C — Formulation solutions

### C1. Furniture company

Let $x$ = chairs and $y$ = tables.

$$
\text{Maximize } Z=500x+800y
$$

subject to

$$
2x+4y\leq100 \quad \text{(carpentry)}
$$

$$
x+2y\leq50 \quad \text{(polishing)}
$$

$$
x,y\geq0.
$$

### C2. Factory products A and B

Let $x$ = units of A and $y$ = units of B.

$$
\text{Maximize } Z=40x+30y
$$

Material:

$$
2x+y\leq100
$$

Labour:

$$
x+2y\leq80
$$

$$
x,y\geq0.
$$

### C3. Diet problem

Let $x$ = servings of X and $y$ = servings of Y.

$$
\text{Minimize } C=30x+20y
$$

Protein:

$$
4x+2y\geq40
$$

Vitamins:

$$
2x+5y\geq30
$$

$$
x,y\geq0.
$$

### C4. Advertising model

Let $x$ = number of TV advertisements and $y$ = number of social-media campaigns.

Reach requirement:

$$
20000x+8000y\geq200000
$$

Budget:

$$
50000x+15000y\leq600000
$$

$$
x,y\geq0.
$$

As written, this is a **feasibility model** because no objective to maximize or minimize is explicitly stated. If the intended goal is to minimize spending, use $\min C=50000x+15000y$ subject to the reach and budget constraints. If the intended goal is to maximize reach, use $\max R=20000x+8000y$ subject to the budget constraint. In a real campaign, $x,y$ may need integer restrictions.

### C5. Three-product LPP

Let $x_1,x_2,x_3$ be units of products $P_1,P_2,P_3$.

$$
\text{Maximize } Z=50x_1+60x_2+40x_3
$$

Machining:

$$
2x_1+3x_2+x_3\leq120
$$

Assembly:

$$
x_1+2x_2+2x_3\leq100
$$

Finishing:

$$
x_1+x_2+2x_3\leq80
$$

$$
x_1,x_2,x_3\geq0.
$$

### C6. Two-product model and feasible region

Let $x$ = units of A and $y$ = units of B.

$$
\text{Maximize } Z=50x+40y
$$

Machine:

$$
2x+y\leq100
$$

Labour:

$$
x+2y\leq80
$$

$$
x,y\geq0.
$$

To identify the feasible region, draw $2x+y=100$ and $x+2y=80$, select the side satisfying each $\leq$ inequality, and intersect those half-planes with the first quadrant. The common region is feasible. No numerical optimum is required by the question.

### C7. Truck transportation

Let $x$ = small-truck trips and $y$ = large-truck trips.

$$
\text{Minimize } C=3000x+5000y
$$

Capacity requirement:

$$
5x+10y\geq100
$$

$$
x,y\geq0.
$$

If trips must be whole numbers:

$$
x,y\in\mathbb{Z}_{\geq0}.
$$

### C8. Three-variable model

$$
\text{Maximize } Z=50x_1+60x_2+40x_3
$$

subject to

$$
2x_1+3x_2+x_3\leq120,
$$

$$
x_1+2x_2+2x_3\leq100,
$$

$$
x_1+x_2+2x_3\leq80,
$$

$$
x_1\geq0,\quad x_2\geq0,\quad x_3\geq0.
$$

## 10.4 Part D — Calculus solutions

### D1. $f(x)=x^2-4x+5$

First derivative:

$$
f'(x)=2x-4.
$$

Set it to zero:

$$
2x-4=0\implies x=2.
$$

Second derivative:

$$
f''(x)=2>0.
$$

Thus $x=2$ is a strict local minimum. Its value is

$$
f(2)=4-8+5=1.
$$

Since

$$
f(x)=(x-2)^2+1\geq1,
$$

it is also the global minimum. Minimum value: **1 at $x=2$**.

### D2. $f(x)=3x^2-12x+7$

$$
f'(x)=6x-12.
$$

$$
6x-12=0\implies x=2.
$$

$$
f''(x)=6>0.
$$

Therefore, $x=2$ is a strict local minimum. Evaluate:

$$
f(2)=3(4)-12(2)+7=12-24+7=-5.
$$

Completing the square confirms the global result:

$$
f(x)=3(x-2)^2-5.
$$

Because $(x-2)^2\geq0$, the **global minimum is $-5$ at $x=2$**. It is both local and global.

### D3. $f(x)=x^2-4x+1$, $0\leq x\leq5$

Differentiate:

$$
f'(x)=2x-4.
$$

Critical point:

$$
2x-4=0\implies x=2.
$$

It lies inside the interval. Evaluate at the critical point and endpoints:

$$
f(0)=1,
$$

$$
f(2)=4-8+1=-3,
$$

$$
f(5)=25-20+1=6.
$$

Compare $1,-3,6$.

- **Global minimum:** $-3$ at $x=2$.
- **Global maximum:** $6$ at $x=5$.

### D4. $f(x)=x^3-3x^2-9x+2$

First derivative:

$$
f'(x)=3x^2-6x-9.
$$

Factor:

$$
f'(x)=3(x^2-2x-3)=3(x-3)(x+1).
$$

Critical points:

$$
x=3,\qquad x=-1.
$$

Second derivative:

$$
f''(x)=6x-6.
$$

At $x=-1$:

$$
f''(-1)=-6-6=-12<0,
$$

so $x=-1$ is a strict local maximum. Its value is

$$
f(-1)=-1-3+9+2=7.
$$

At $x=3$:

$$
f''(3)=18-6=12>0,
$$

so $x=3$ is a strict local minimum. Its value is

$$
f(3)=27-27-27+2=-25.
$$

**Answer:** local maximum $7$ at $x=-1$; local minimum $-25$ at $x=3$. Since this is an unrestricted cubic, it has no global maximum or global minimum over all real numbers: it tends to $+\infty$ as $x\to+\infty$ and to $-\infty$ as $x\to-\infty$.

### D5. $f(x)=x^3$

$$
f'(x)=3x^2.
$$

Set $f'(x)=0$:

$$
3x^2=0\implies x=0.
$$

Second derivative:

$$
f''(x)=6x,\qquad f''(0)=0.
$$

The second derivative test is inconclusive. Use the first derivative test: $f'(x)=3x^2>0$ for $x\neq0$, on both sides of zero. The function is increasing through zero, so $x=0$ is **not a local maximum or minimum**; it is a stationary inflection point.

### D6. $f(x,y)=x^2+y^2$

First partial derivatives:

$$
f_x=2x,\qquad f_y=2y.
$$

At a stationary point:

$$
2x=0,\quad2y=0\implies(x,y)=(0,0).
$$

Hessian:

$$
H=\begin{bmatrix}2&0\\0&2\end{bmatrix}.
$$

The Hessian is positive definite, so $(0,0)$ is a strict local minimum. Since $x^2+y^2\geq0$ for all $(x,y)$, it is also a global minimum with value $0$.

### D7. $f(x,y)=x^2-y^2$

$$
f_x=2x,\qquad f_y=-2y.
$$

The stationary point is $(0,0)$. The Hessian is

$$
H=\begin{bmatrix}2&0\\0&-2\end{bmatrix}.
$$

It has one positive and one negative eigenvalue, so it is indefinite. Therefore $(0,0)$ is a **saddle point**, not a local maximum or minimum.

### D8. Absolute extrema on $[1,4]$

Calculate the function values at all candidates:

$$
f(1),\quad f(2),\quad f(3),\quad f(4).
$$

Then compare these four values. The largest is the absolute/global maximum and the smallest is the absolute/global minimum. The actual numerical values cannot be found without the expression for $f(x)$.

## 10.5 Part E — Tutorial-sheet engineering solutions

### E1. Production planning

Let $A$ and $B$ be weekly units of products A and B.

$$
\text{Maximize } Z=40A+30B
$$

subject to

$$
2A+B\leq100 \quad \text{(machining)}
$$

$$
A+2B\leq80 \quad \text{(assembly)}
$$

$$
A\leq40,\quad B\leq50,\quad A,B\geq0.
$$

The intersection of the two resource equalities is

$$
2A+B=100,\qquad A+2B=80.
$$

From the first equation, $B=100-2A$. Substitute:

$$
A+2(100-2A)=80
$$

$$
A+200-4A=80\implies -3A=-120\implies A=40.
$$

Then $B=100-2(40)=20$.

Profit:

$$
Z=40(40)+30(20)=1600+600=2200.
$$

This satisfies the demand caps. Since $A=40$ and the resource constraints meet at the same point, the optimal production plan is **40 units of A and 20 units of B**, with maximum profit **$2,200 per week**.

### E2. Power generation

Let $C$ = coal generation in MWh and $G$ = gas generation in MWh.

$$
\text{Minimize } Z=60C+80G
$$

subject to

$$
C+G\geq300,
$$

$$
C\leq180,\qquad G\leq200,
$$

$$
2C+G\leq500,
$$

$$
C,G\geq0.
$$

Coal is cheaper, so use as much coal as possible while satisfying the constraints. Set $C=180$. To meet demand, $G\geq120$. Taking $G=120$ gives

$$
C+G=300,\qquad 2C+G=360+120=480\leq500.
$$

Cost:

$$
Z=60(180)+80(120)=10800+9600=20400.
$$

**Optimal plan:** coal $180$ MWh and gas $120$ MWh. Minimum cost: **$20,400 per day**.

### E3. Chemical production

Let $A,B$ be units of chemicals A and B.

$$
\text{Maximize } Z=50A+70B
$$

subject to

$$
3A+2B\leq180,
$$

$$
2A+4B\leq200,
$$

$$
A\leq40,\qquad A,B\geq0.
$$

At the intersection of the two resource constraints:

$$
3A+2B=180,
$$

$$
A+2B=100 \quad \text{(second constraint divided by 2)}.
$$

Subtract the second equation from the first:

$$
2A=80\implies A=40.
$$

Then

$$
40+2B=100\implies B=30.
$$

Profit:

$$
Z=50(40)+70(30)=2000+2100=4100.
$$

The plan meets $A\leq40$, and both resource limits are binding. **Optimal plan:** 40 units of A and 30 units of B. Maximum profit: **$4,100 per week**.

### E4. Transportation

Let $x$ = tonnes from Plant 1 and $y$ = tonnes from Plant 2.

$$
\text{Minimize } C=8x+6y
$$

subject to

$$
x+y\geq120,
$$

$$
x\leq70,\qquad y\leq80,
$$

$$
x,y\geq0.
$$

Plant 2 is cheaper, so use its maximum supply $y=80$. The remaining requirement is $x=40$. This is within Plant 1's capacity.

$$
C=8(40)+6(80)=320+480=800.
$$

**Optimal plan:** 40 tonnes from Plant 1 and 80 tonnes from Plant 2. Minimum cost: **$800**.

### E5. Steel mill

Let $B$ = tonnes of bars and $R$ = tonnes of rods.

$$
\text{Maximize } Z=55B+45R
$$

subject to

$$
4B+3R\leq240,
$$

$$
2B+R\leq100,
$$

$$
R\leq50,\qquad B,R\geq0.
$$

At the intersection of the resource constraints:

$$
4B+3R=240,\qquad 2B+R=100.
$$

From the second equation, $R=100-2B$. Substitute:

$$
4B+3(100-2B)=240
$$

$$
4B+300-6B=240\implies B=30.
$$

Then $R=100-60=40$.

Profit:

$$
Z=55(30)+45(40)=1650+1800=3450.
$$

The rod cap is satisfied. **Optimal plan:** 30 tonnes of bars and 40 tonnes of rods. Maximum profit: **$3,450 per week**.

### E6. Electronics manufacturing

Let $x$ = Model I units and $y$ = Model II units.

$$
\text{Maximize } Z=120x+100y
$$

subject to

$$
5x+4y\leq400,
$$

$$
2x+3y\leq180,
$$

$$
x\leq60,\qquad x,y\geq0.
$$

At $x=60$, the SMT constraint gives

$$
300+4y\leq400\implies y\leq25.
$$

The inspection constraint gives

$$
120+3y\leq180\implies y\leq20.
$$

Thus $y\leq20$, so the best feasible value at $x=60$ is $y=20$.

$$
Z=120(60)+100(20)=7200+2000=9200.
$$

To check the resource-boundary intersection, solving both resource equalities gives $x=480/7\approx68.57$, which violates $x\leq60$. The cap is therefore important. **Optimal plan:** 60 units of Model I and 20 units of Model II. Maximum profit: **$9,200 per week**.

### E7. Construction materials

Let $C$ = concrete batches and $A$ = asphalt batches.

$$
\text{Minimize } Z=90C+110A
$$

subject to

$$
C+A\geq150,
$$

$$
3C+2A\geq360,
$$

$$
C\leq100,\qquad C,A\geq0.
$$

Concrete is cheaper per batch and also supplies more strength per batch. Because $C\leq100$, take $C=100$. The batch requirement then requires $A\geq50$. At $A=50$,

$$
C+A=150,\qquad3C+2A=300+100=400\geq360.
$$

Cost:

$$
Z=90(100)+110(50)=9000+5500=14500.
$$

**Optimal plan:** 100 concrete batches and 50 asphalt batches. Minimum cost: **$14,500**.

### E8. Water blending

Let $x$ = million litres from Source I and $y$ = million litres from Source II.

$$
\text{Minimize } C=5x+7y
$$

Total volume:

$$
x+y=100.
$$

Impurity limit:

$$
0.02x+0.08y\leq5.
$$

$$
x,y\geq0.
$$

Since Source I is cheaper and has fewer impurities, test $x=100,y=0$. Total impurity is

$$
0.02(100)+0.08(0)=2\leq5.
$$

Cost:

$$
C=5(100)+7(0)=500.
$$

**Optimal plan:** 100 million litres from Source I and none from Source II. Minimum cost: **$500** (in the units implied by the stated rates). The impurity limit is satisfied.

### E9. Solar panel manufacturing

Let $R$ = residential panels and $C$ = commercial panels.

$$
\text{Maximize } Z=200R+350C
$$

subject to

$$
6R+10C\leq600,
$$

$$
4R+3C\leq300,
$$

$$
C\leq30,\qquad R,C\geq0.
$$

At $C=30$, the machine constraint gives

$$
6R+300\leq600\implies R\leq50.
$$

The labour constraint gives

$$
4R+90\leq300\implies R\leq52.5.
$$

Thus $R=50,C=30$ is feasible. Profit:

$$
Z=200(50)+350(30)=10000+10500=20500.
$$

For comparison, the intersection of the two resource equalities is $R=600/11\approx54.55$, $C=300/11\approx27.27$, giving a slightly lower profit. The cap $C\leq30$ is binding at the optimum. **Optimal plan:** 50 residential and 30 commercial panels. Maximum profit: **$20,500 per week**.

### E10. Warehouse logistics

Let $T$ = truck trips and $R$ = rail trips.

$$
\text{Minimize } C=500T+300R
$$

subject to

$$
20T+50R\geq500,
$$

$$
T\leq20,\qquad R\leq10,
$$

$$
T,R\in\mathbb{Z}_{\geq0}.
$$

Ten rail trips carry

$$
50(10)=500\text{ tonnes}.
$$

Their cost is

$$
C=300(10)=3000.
$$

Because rail carries more tonnes at lower cost per tonne ($$300/50=\$6$ per tonne, compared with $$500/20=\$25$ per tonne), replacing rail capacity with trucks cannot reduce cost. **Optimal plan:** 0 truck trips and 10 rail trips. Minimum cost: **$3,000**.

## 10.6 Additional formulation practice — worked answers

### Question: production with demand caps
A product A earns ₹40 and B earns ₹30. A uses 2 units of raw material and 1 labour hour; B uses 1 unit of material and 2 labour hours. Material capacity is 100 and labour capacity is 80. Write the model.

Let $x,y$ be units of A and B.

$$
\max Z=40x+30y
$$

$$
2x+y\leq100,\qquad x+2y\leq80,\qquad x,y\geq0.
$$

### Question: a minimization problem with minimum requirements
Let $x,y$ be quantities costing ₹5 and ₹7 each. At least 100 total units are needed, and quality requires $2x+y\geq120$.

$$
\min C=5x+7y
$$

$$
x+y\geq100,\qquad2x+y\geq120,\qquad x,y\geq0.
$$

### Question: identify problem type
1. $\min x^2+y^2$: unconstrained nonlinear optimization.
2. $\max 5x+3y$ subject to $x+y\leq10$: constrained linear optimization.
3. $\min 5x+3y$ with $x,y\in\mathbb{Z}_{\geq0}$: integer linear optimization.
4. $\min f(x)$ where the objective is a black-box simulation and GA is used: simulation-based heuristic optimization.
5. Select whether to build each of three facilities, with each decision 0 or 1: binary optimization.

---

# 11. LAST-MINUTE REVISION SHEET

## Definitions to memorize
- **Optimization:** finding the best feasible solution.
- **Objective function:** quantity to maximize or minimize.
- **Decision variables:** unknown choices.
- **Constraints:** restrictions or requirements.
- **Feasible solution:** satisfies all constraints.
- **Feasible region:** all feasible solutions.
- **Local optimum:** best in a neighbourhood.
- **Global optimum:** best in the entire feasible domain.
- **LPP:** linear objective and linear constraints.
- **GA:** evolution-inspired search method.
- **PSO:** swarm-inspired optimization method.

## Formula recap

### First-order condition
$$
f'(x^*)=0
$$

### Second derivative test
$$
f''(x^*)>0\Rightarrow\text{local minimum}
$$

$$
f''(x^*)<0\Rightarrow\text{local maximum}
$$

$$
f''(x^*)=0\Rightarrow\text{inconclusive}
$$

### Quadratic vertex
$$
f(x)=ax^2+bx+c,\qquad x^*=-\frac{b}{2a}
$$

### Two-variable stationary point
$$
f_x=0,\qquad f_y=0
$$

### Two-variable Hessian test
$$
D=f_{xx}f_{yy}-(f_{xy})^2
$$

- $D>0,\ f_{xx}>0$: local minimum.
- $D>0,\ f_{xx}<0$: local maximum.
- $D<0$: saddle point.
- $D=0$: inconclusive.

## Formulation checklist
Before finishing any LPP answer, verify:
- [ ] Decision variables are defined.
- [ ] Maximize/minimize is clearly stated.
- [ ] Objective coefficients match the question.
- [ ] Every resource constraint is included.
- [ ] Every demand/capacity/quality constraint is included.
- [ ] Inequality directions match the wording.
- [ ] Non-negativity restrictions are included.
- [ ] Integer/binary restrictions are included if required.

## Calculus checklist
- [ ] Differentiate correctly.
- [ ] Solve $f'(x)=0$.
- [ ] Use $f''(x)$ or the first derivative test.
- [ ] If the interval is closed, check both endpoints.
- [ ] Give the optimum point **and** the objective value.
- [ ] Do not claim global optimality from the second derivative test alone unless the function/domain provides sufficient justification.

## Final exam strategy
1. For a 2-mark definition, give a precise definition and one example.
2. For a 6-mark theory answer, use a definition, key points, a comparison/table or example, and a short conclusion.
3. For an LPP formulation, show variables, objective, each constraint with a label, and non-negativity.
4. For calculus, show derivative, critical point, classification, function value, and global/local conclusion.
5. For AI, name methods (GA, PSO, neural networks/RL/ACO), explain the basic idea, give applications, and state both advantages and limitations.
6. Read every inequality phrase carefully: **at most $\leq$, at least $\geq$, exactly $=$**.

**End of Unit I notes.**
