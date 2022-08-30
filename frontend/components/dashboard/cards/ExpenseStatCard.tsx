import GenericStatCard from "./GenericStatCard"

type Props = {

}

const ExpenseStatCard = ({

}: Props) => {
  return (  
    <GenericStatCard
      title="Expense"
      subtitle="Estimated system operational cost"
      number={23}
      quantifier="USD"
    >
    </GenericStatCard>
  ) 
}

export default ExpenseStatCard