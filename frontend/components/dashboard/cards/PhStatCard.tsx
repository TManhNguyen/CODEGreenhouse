import GenericStatCard from "./GenericStatCard"

type Props = {
  ph: number
}

const PhStatCard = ({
  ph
}: Props) => {
  return (  
    <GenericStatCard
      title="pH Level"
      subtitle={(ph == 7) ? "Medium's pH level is balance." : "Please balance the medium solution."}
      number={ph}
      quantifier=""
      isOptimal={ph == 7}
    >
    </GenericStatCard>      
  ) 
}

export default PhStatCard