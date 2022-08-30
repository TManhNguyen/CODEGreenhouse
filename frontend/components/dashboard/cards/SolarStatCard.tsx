import GenericStatCard from "./GenericStatCard"

type Props = {
  solar: number
}

const SolarStatCard = ({
  solar
}: Props) => {
  return (
    <GenericStatCard
      title="Solar Energy Harvesting"
      subtitle={ solar > 5 ? "Harvesting high power." : "Harvesting low power."}
      number={Math.round(solar/10)}
      quantifier="W"
      isOptimal={solar > 5}
    >
      {/* <div className="flex flex-col w-full">
        <button className="bg-transparent text-left text-red-500 font-medium hover:text-red-600">
          Do nothing
        </button>
      </div> */}
    </GenericStatCard>
  )
}

export default SolarStatCard
