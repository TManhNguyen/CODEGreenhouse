import GenericSlider from './GenericSlider';

type Props = {

}

const LightingSlider = ({
}: Props) => {
  const marks = {
    0: '0',
    20: '20',
  }
  return (  
    <GenericSlider
      title="Lighting"
      subtitle="PPFD (Photosynthetic Photon Flux Density)" 
      min={0} 
      max={20} 
      defaultValue={10} 
      marks={marks} 
      included={false}
      tipFormatter={(v) => (`${v} PPFD`)} />
  ) 
}

export default LightingSlider